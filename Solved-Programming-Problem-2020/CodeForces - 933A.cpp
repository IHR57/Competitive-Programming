//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define mem(a, b) (memset(a, b, sizeof(a)))
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define INF 2147483647
#define MOD 1000000007
#define MAX 2005
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> pii;
typedef vector<ii> vii;
typedef priority_queue<int,vector<int>,greater<int> > PQ;
 
int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}
 
int arr[MAX], cs[MAX][2], dp[MAX][MAX];

int solve(int i, int j) 
{
    if(i > j)
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    if(arr[i] == 2)
        return dp[i][j] = 1 + solve(i + 1, j);
    if(arr[j] == 1)
        return dp[i][j] = 1 + solve(i, j - 1);

    return dp[i][j] = max(solve(i + 1, j), solve(i, j - 1));
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n;

    scanf("%d", &n);

    int cnt = 1;

    for(int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
        cs[i][0] = cs[i-1][0] + (arr[i] == 1);
        cs[i][1] = cs[i-1][1] + (arr[i] == 2);
    }     

    mem(dp, -1);

    int Max = solve(1, n);

    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            int cnt = cs[i-1][0] + cs[n][1] - cs[j][1];
            cnt += solve(i, j);
            Max = max(Max, cnt);
        }
    }


    cout<<Max<<endl;

    return 0;
}