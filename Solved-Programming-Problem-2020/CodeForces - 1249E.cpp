//Date: 18/03/2020
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


int dp[MAX][2], a[MAX], b[MAX], n, c;

int solve(int pos, int type)
{
    if(n < 0)
        return 0;

    if(dp[pos][type] != -1)
        return dp[pos][type];

    int ret = 2e9;
    for(int i = 0; i < 2; i++){
        if(pos == n - 2)
            ret = min(ret, ((i == 0) ? a[pos] : c + b[pos]) + solve(pos - 1, i));
        else{
            if(i == 1){
                ret = min(ret, ((type == 1) ? b[pos] : c + b[pos]) + solve(pos - 1, i));
            }
            else
                ret = min(ret, a[pos] + solve(pos - 1, i));
        }
    }

    return dp[pos][type] = ret;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    cin>>n>>c;

    for(int i = 0; i < n - 1; i++){
        cin>>a[i];
    }
    for(int i = 0; i < n - 1; i++)
        cin>>b[i];

    memset(dp, -1, sizeof(dp));

    vector<int> v;
    for(int i = n - 2; i >= 0; i--){
        int res = solve(i, 0);
        v.pb(res);
    }

    v.pb(0);
    reverse(v.begin(), v.end());

    for(int i = 0; i < v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    return 0;

}
