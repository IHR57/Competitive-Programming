#include <bits/stdc++.h>
#define MAX 100005
#define MOD 1000000007
using namespace std;

typedef long long ll;
vector<int> graph[MAX];
int visited[MAX];

ll bigMod(ll a, ll b)
{
    if(b == 0)
        return 1;
    ll x = bigMod(a, b >> 1);
    x = (x * x) % MOD;
    if(b % 2 == 1)
        x = (x * a) % MOD;
    return x;
}

int dfs(int u)
{
    visited[u] = 1;
    int ret = 1;
    for(int i = 0; i < graph[u].size(); i++){
        int v = graph[u][i];
        if(!visited[v]){
            ret += dfs(v);
        }
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int u, v, x;
    ll n, k;

    cin>>n>>k;

    for(int i = 0; i < n - 1; i++){
        cin>>u>>v>>x;
        if(x != 1){
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
    }

    ll ans = bigMod(n, k);

    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            ans -= bigMod(dfs(i), k);
            if(ans < 0)
                ans += MOD;
        }
    }

    cout<<ans<<endl;

    return 0;
}
