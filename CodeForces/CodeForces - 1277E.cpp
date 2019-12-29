//Date: 15/12/19
#include <bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1.0)
#define INF 2147483647
#define MOD 1000000007
#define MAX 300005
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

bool check(ll mask, ll pos) { return (bool) (mask & (1LL<<pos)); };
void Set(int mask, int pos) { mask = (mask | (1<<pos)); };

vector<int> graph[MAX];
int a, b, vis[MAX], cnt;

void dfs(int u, int x)
{
    vis[u] = 1;
    for(int i = 0; i < graph[u].size(); i++){
        int v = graph[u][i];
        if(!vis[v] && v != x){
            cnt++;
            dfs(v, x);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, m, u, v, test;

    cin>>test;

    while(test--){
        cin>>n>>m>>a>>b;
        for(int i = 0; i < m; i++){
            cin>>u>>v;
            graph[u].pb(v);
            graph[v].pb(u);
        }

        for(int i = 0; i <= n; i++)
            vis[i] = 0;
        ll ans = 1;
        cnt = 0;
        dfs(b, a);
        ans *= (1LL * (n - cnt - 2));
        for(int i = 0; i <= n; i++)
            vis[i] = 0;
        cnt = 0;
        dfs(a, b);
        ans *= (1LL * (n - cnt - 2));

        cout<<ans<<endl;

        for(int i = 0; i <= n; i++)
            graph[i].clear();
    }

    return 0;
}