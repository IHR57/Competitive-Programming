#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define pi 3.1415926535897932384
#define INF 2147483647
#define MOD 1000000007
#define MAX 200005
using namespace std;

typedef long long ll;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int cost[MAX];
vector<int> graph[MAX];

void dfs(int u, int par)
{
    for(int i = 0; i < graph[u].size(); i++){
        int v = graph[u][i];
        if(v == par)
            continue;
        cost[v] += cost[u];
        dfs(v, u);
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q, u, v;
    cin>>n>>q;

    for(int i = 0; i < n - 1; i++){
        cin>>u>>v;
        graph[u].pb(v);
    }

    for(int i = 0; i < q; i++){
        cin>>u>>v;
        cost[u] += v;
    }

    dfs(1, -1);

    for(int i = 1; i <= n; i++){
        cout<<cost[i]<<" ";
    }
    cout<<endl;

    return 0;
}

