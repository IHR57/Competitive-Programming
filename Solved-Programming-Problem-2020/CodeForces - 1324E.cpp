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

int dp[MAX][MAX], l, r, n, h;
int arr[MAX];

int solve(int pos, int hour) {
    if(pos == n){
        if(hour >= l && hour <= r)
            return 1;
        return 0;
    }

    if(dp[pos][hour] != -1)
        return dp[pos][hour];

    int ret = (hour >= l && hour <= r) + solve(pos + 1, (hour + arr[pos] - 1) % h);
    ret = max(ret, (hour >= l && hour <= r) + solve(pos + 1, (hour + arr[pos]) % h));

    return dp[pos][hour] = ret;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cin>>n>>h>>l>>r;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    memset(dp, -1, sizeof(dp));
    int res = solve(0, 0);
    if(l == 0)
        res--;
    
    cout<<res<<endl;

    return 0;
}