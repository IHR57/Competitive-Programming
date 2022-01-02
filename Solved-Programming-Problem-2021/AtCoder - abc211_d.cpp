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
#define MOD 1000000007
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

vector<int> graph[MAX];
ll dp[MAX];
int vis[MAX], dst[MAX];

void bfs(int  src)
{
    vis[src] = 1;
    dst[src] = 0;
    dp[src] = 1;
    queue<int> q;
    q.push(src);

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        int minDist = INT_MAX;
        for(int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i];
            if(vis[v])
                minDist = min(minDist, dst[v]);
        }

        if(dp[u] == 1e9)
            dp[u] = 0;
        for(int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i];
            if(vis[v]) {
                if(dst[v] == minDist) {
                    dp[u] = (dp[u] + dp[v]) % MOD;
                }
            }
            if(!vis[v]) {
                vis[v] = 1;
                q.push(v);
                dst[v] = dst[u] + 1;
            }
        }
    }
}

void solve()
{
    int n, m;

    cin>>n>>m;

    REP(i, m) {
        int u, v;
        cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    FOR(i, 1, n)    dp[i] = 1e9;
    bfs(1);

    if(dp[n] == 1e9)    cout<<0<<endl;
    else    cout<<dp[n]<<endl;

    return;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int test = 1;

    //cin>>test;

    while(test--) {
        solve();
    }

    return 0;
}

