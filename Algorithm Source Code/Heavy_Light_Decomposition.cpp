#include <bits/stdc++.h>
#define MAX 100005
#define EPS 1e-8
#define MOD 1000000007
using namespace std;

typedef long long ll;

vector<int> graph[MAX];
int parent[MAX], heavy[MAX], depth[MAX], sbt[MAX];
int chain[MAX], head[MAX];

void dfs(int u, int par)
{
    sbt[u] = 1;
    for(int i = 0; i < graph[u].size(); i++){
        int v = graph[u][i];
        if(v == par)
            continue;
        parent[v] = u;
        depth[v] = depth[u] + 1;
        dfs(v, u);
        sbt[u] += sbt[v];
        if(heavy[u] == -1 || sbt[v] > sbt[heavy[u]]){
            heavy[u] = v;
        }
    }
}

void heavyLight(int n)
{
    memset(heavy, -1, sizeof(heavy));
    parent[0] = -1, depth[0] = 0;
    dfs(0, -1);

    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(parent[i] == -1 || heavy[parent[i]] != i){
            for(int k = i; k != -1; k = heavy[k]){
                chain[k] = cnt, head[k] = i;
            }
            cnt++;
        }
    }
}

int lca(int u, int v)
{
    while(chain[u] != chain[v]){
        if(depth[head[u]] > depth[head[v]]){
            u = parent[head[u]];
        }
        else
            v = parent[head[v]];
    }
    return depth[u] < depth[v] ? u : v;
}

void viewDetails(int n)
{
    printf("Heavy Edge\n");
    for(int i = 0; i < n; i++){
        printf("%d -- %d\n", i, heavy[i]);
    }
    printf("\n");
    printf("Chain:\n");
    for(int i = 0; i < n; i++){
        printf("%d -- %d\n", i, chain[i]);
    }
    printf("\n");
    printf("Head:\n");
    for(int i = 0; i < n; i++){
        printf("%d -- %d\n", i, head[i]);
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, u, v;

    scanf("%d", &n);

    for(int i = 0; i < n - 1; i++){
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    heavyLight(n);
    //viewDetails(n);
    cout<<lca(7, 12)<<endl;

    return 0;
}