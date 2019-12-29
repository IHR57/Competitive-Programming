//Date: 11/10/19
#include <bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define pi 3.1415926535897932384
#define INF 2147483647
#define EPS 1e-8
#define MOD 1000000007
#define MAX 200005
using namespace std;
 
typedef long long ll;
typedef pair<int, int> ii;
 
int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

vector<string> vs, rev;
ll dp[MAX][2];
int c[MAX], n;

/*
ll solve(int pos, int same)
{
    if(pos == n - 1){
        if(same == 0)
            return 0;
        else
            return c[pos];
    }
    if(dp[pos][same] != -1)
        return dp[pos][same];

    ll ret = 1e16;
    if(same == 0){
        if(vs[pos+1] >= vs[pos]){
            ret = min(ret, solve(pos + 1, 0));
        }
        if(rev[pos+1] >= vs[pos]){
            ret = min(ret, solve(pos + 1, 1));
        }
    }
    else{
        if(vs[pos+1] >= rev[pos]){
            ret = min(ret, c[pos] + solve(pos + 1, 0));
        }
        if(rev[pos+1] >= rev[pos]){
            ret = min(ret, c[pos] + solve(pos + 1, 1));
        }
    }

    return dp[pos][same] = ret;
}
*/

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    string str;

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>c[i];
    }

    for(int i = 0; i < n; i++){
        cin>>str;
        vs.pb(str);
        reverse(str.begin(), str.end());
        rev.pb(str);
    }

    for(int i = 0; i <= n; i++)
        dp[i][0] = dp[i][1] = 1e16;

    dp[0][0] = 0, dp[0][1] = c[0];

    for(int i = 1; i < n; i++){
        if(vs[i] >= vs[i-1])
            dp[i][0] = min(dp[i][0], dp[i-1][0]);
        if(rev[i] >= vs[i-1])
            dp[i][1] = min(dp[i][1], dp[i-1][0] + c[i]);
        if(vs[i] >= rev[i-1])
            dp[i][0] = min(dp[i][0], dp[i-1][1]);
        if(rev[i] >= rev[i-1])
            dp[i][1] = min(dp[i][1], dp[i-1][1] + c[i]);

    }

    ll ans = min(dp[n-1][0], dp[n-1][1]);

    (ans >= 1e16) ? cout<<"-1"<<endl : cout<<ans<<endl;

    return 0;
}