//Problem ID: CodeForces - 961B (Lecture Sleep)
//Programmer: IQBAL HOSSAIN     Description: DP/Brute Force
//Date: 26/08/19
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define INF 1e17
#define MOD 1000000007
#define MAX 200005
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

ll dp[MAX][2], arr[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, k;

    cin>>n>>k;

    for(int i = 1; i <= n; i++){
        cin>>arr[i];
    }

    int x;
    for(int i = 1; i <= n; i++){
        cin>>x;
        dp[i][0] = dp[i-1][0] + arr[i];
        if(x == 1)
            dp[i][1] = dp[i-1][1] + arr[i];
        else
            dp[i][1] = dp[i-1][1];
    }

    ll Max = 0;
    for(int i = 1; i <= n - k + 1; i++){
        ll temp = (dp[i+k-1][0] - dp[i-1][0]) + (dp[n][1] - dp[i+k-1][1]) + dp[i-1][1];
        Max = max(Max, temp);
    }

    cout<<Max<<endl;

    return 0;
}
