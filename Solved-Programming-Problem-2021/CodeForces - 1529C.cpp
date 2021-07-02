//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define mem(a, b) (memset(a, b, sizeof(a)))
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define min3(a,b,c)     min(a,min(b,c))
#define max3(a,b,c)     max(a,max(b,c))
#define min4(a,b,c,d)   min(a,min(b,min(c,d)))
#define max4(a,b,c,d)   max(a,max(b,max(c,d)))
#define FOR(i,a,b)      for(int i=a;i<=b;i++)
#define ROF(i,a,b)      for(int i=a;i>=b;i--)
#define REP(i,b)        for(int i=0;i<b;i++)
#define all(v)          v.begin(),v.end()
#define SORT(v)         sort(v.begin(),v.end())
#define RSORT(v)        sort(v.rbegin(),v.rend())
#define REV(v)          reverse(v.begin(),v.end())
#define INF 2147483647
#define MOD 998244353
#define MAX 300005
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> pii;
typedef pair<ll, ll> LL;
typedef vector<ii> vii;
typedef priority_queue<int,vector<int>,greater<int> > PQ;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int setBit(int mask, int pos){return mask = mask | (1<<pos);}
bool checkBit(int mask, int pos){return (bool)(mask & (1<<pos));}

ll dp[MAX][2];
pair<ll, ll> vp[MAX];
vi graph[MAX];

void dfs(int u, int par)
{
    for(int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        if(v == par)
            continue;
        dfs(v, u);
        dp[u][0] += max(abs(vp[u].ff - vp[v].ss) + dp[v][1], abs(vp[u].ff - vp[v].ff) + dp[v][0]);
        dp[u][1] += max(abs(vp[u].ss - vp[v].ss) + dp[v][1], abs(vp[u].ss - vp[v].ff) + dp[v][0]);
    }
}

void solve()
{
    int n;

    cin>>n;

    REP(i, n)   dp[i][0] = dp[i][1] = 0;
    REP(i, n)   graph[i].clear();

    REP(i, n)   cin>>vp[i].ff>>vp[i].ss;
    REP(i, n - 1) {
        int u, v;
        cin>>u>>v;
        u--, v--;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    dfs(0, -1);

    cout<<max(dp[0][0], dp[0][1])<<endl;

    return;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int test = 1;

    cin>>test;

    while(test--) {
        solve();
    }

    return 0;
}

