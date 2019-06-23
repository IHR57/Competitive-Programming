//Problem ID: CodeChef - INTRPATH (Intersecting Paths)
//Description: LCA/DFS
//Date: 21/06/19
//Solution Idea: https://discuss.codechef.com/t/intersecting-paths/27997/4
#include <bits/stdc++.h>
#define MAX 300005
using namespace std;

typedef long long ll;

vector<int> graph[MAX];
int parent[MAX][20];
ll depth[MAX], sbt[MAX];
ll ans[MAX], ans1[MAX], ans2[MAX];
ll cs1[MAX], cs2[MAX];

int n, q;

void dfs(int u, int par)
{
    parent[u][0] = par;
    ans2[u] = 0;
    (par == -1) ? depth[u] = 0 : depth[u] = depth[par] + 1;
    sbt[u] = 1;

    for(int i = 0; i < graph[u].size(); i++){
        int v = graph[u][i];
        if(v == par)
            continue;
        dfs(v, u);
        sbt[u] += sbt[v];
    }

    ans[u] = (sbt[u] * 1LL * (sbt[u] + 1));
    for(int i = 0; i < graph[u].size(); i++){
        int v = graph[u][i];
        if(v != par){
            ans[u] -= (sbt[v] * 1LL * (sbt[v] + 1));
        }
    }
    ans[u] /= 2;
    ans1[u] = ans[u] + sbt[u] * 1LL * (n - sbt[u]);
}

void dfs1(int u, int par)
{
    if(par == -1){
        cs1[u] = ans[u];
        cs2[u] = ans2[u];
    }
    else{
        cs1[u] = cs1[par] + ans[u];
        cs2[u] = cs2[par] + ans2[u];
    }

    for(int i = 0; i < graph[u].size(); i++){
        int v = graph[u][i];
        if(v != par){
            ans2[v] = (sbt[u] - sbt[v]) * 1LL * sbt[v];
            dfs1(v, u);
        }
    }

}

void initLCA()
{
    for(int j = 1; j < 20; j++){
        for(int i = 0; i < n; i++){
            if(parent[i][j-1] != -1){
                parent[i][j] = parent[parent[i][j-1]][j-1];
            }
            else{
                parent[i][j] = -1;
            }
        }
    }
}

int LCA(int u, int v)
{
    if(depth[u] < depth[v])
        swap(u, v);


    for(int i = 19; i >= 0; i--){
        if(depth[u] - (1 << i) >= depth[v]){
            u = parent[u][i];
        }
    }

    if(u == v)
        return u;
    for(int i = 19; i >= 0; i--){
        if(parent[u][i] != parent[v][i]){
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}

int getParent(int u, int dep)
{
    for(int i = 19; i >= 0; i--){
        if(depth[u] - (1 << i) >= dep){
            u = parent[u][i];
        }
    }

    return u;
}

ll compute(int u, int v)
{
    int kthParent = getParent(v, depth[u] + 1);
    ll sum = 0;
    sum = cs1[v] - cs1[u];
    sum -= (cs2[v] - cs2[kthParent]);

    sum += ans1[u];
    sum -= (sbt[kthParent] * (n - sbt[kthParent]));

    return sum;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int u, v, test;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &n, &q);

        for(int i = 0; i < n - 1; i++){
            scanf("%d %d", &u, &v);
            u--, v--;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        dfs(0, -1);
        initLCA();
        dfs1(0, -1);
        for(int i = 0; i < q; i++){
            scanf("%d %d",  &u, &v);
            u--, v--;
            // cout<<cs1[v]<<" "<<cs1[u]<<endl;
            // cout<<cs2[v]<<" "<<cs2[u]<<endl;
            if(depth[u] > depth[v])
                swap(u, v);
            int lca = LCA(u, v);
            if(u == v){
                printf("%lld\n", ans1[u]);
            }
            else if(lca == u){
                printf("%lld\n", compute(u, v));
            }
            else{
                int p = getParent(v, depth[lca] + 1);
                int r = getParent(u, depth[lca] + 1);
                ll res = compute(lca, v) + compute(lca, u) + (sbt[p] * 1LL * sbt[r]) - ans1[lca];
                printf("%lld\n", res);
            }
        }

        for(int i = 0; i < MAX; i++)
            graph[i].clear();

    }

    return 0;
}