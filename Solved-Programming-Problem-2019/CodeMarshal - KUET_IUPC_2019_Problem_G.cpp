//Problem ID: KUET - IUPC 2019 (Problem - G)
//Programmer: IQBAL HOSSAIN     Description: Graph
//Date: 09/09/18
//Problem Link: https://algo.codemarshal.org/contests/kuet-iupc-19/problems/G
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
#define MAX 100005
using namespace std;

typedef unsigned long long ll;
typedef pair<int, int> ii;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int comp[MAX], dist[MAX], c, vis[MAX], totlen[MAX], root;
bool notCyclic[MAX];
int depth[MAX], T[MAX];
int parent[MAX][18];
map<ii, int> mp;
vector<int> graph[MAX];

void dfs(int from, int u, int dep)
{
    vis[u] = 1;
    comp[u] = c;
    T[u] = from;
    depth[u] = dep;
    if(graph[u].size() == 1)
        notCyclic[c] = true;
    for(int i = 0; i < graph[u].size(); i++){
        int v = graph[u][i];
        if(vis[v]){
            continue;
        }
        totlen[c] += mp[mk(u, v)];
        dist[v] += dist[u] + mp[mk(v, u)];
        dfs(u, v, dep + 1);
    }
}

void LCAinit(int n)
{
    memset(parent, -1, sizeof(parent));

    for(int i = 0; i < n; i++){
        parent[i][0] = T[i];
    }

    for(int j = 1; (1<<j) < n; j++){
        for(int i = 0; i < n; i++){
            if(parent[i][j-1] != -1){
                parent[i][j] = parent[parent[i][j-1]][j-1];
            }
        }
    }
}

int LCAquery(int p, int q)
{
    if(depth[p] < depth[q])
        swap(p, q);

    int lg = 1;
    while(1){
        int next = lg + 1;
        if((1<<next) > depth[p]){
            break;
        }
        lg++;
    }

    for(int i = lg; i >= 0; i--){
        if(depth[p] - (1<<i) >= depth[q]){
            p = parent[p][i];
        }
    }

    if(p == q)
        return p;

    for(int i = lg; i >= 0; i--){
        if(parent[p][i] != -1 && parent[p][i] != parent[q][i]){
            p = parent[p][i];
            q = parent[q][i];
        }
    }

    return T[p];
}


int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifdef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int test, caseno = 1, n, m, u, v, w;
    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &n, &m);
        for(int i = 0; i < m; i++){
            scanf("%d %d %d", &u, &v, &w);
            u--, v--;
            graph[u].pb(v);
            graph[v].pb(u);
            mp[mk(u, v)] = mp[mk(v, u)] = w;
        }

        c = 0;
        memset(vis, 0, sizeof(vis));
        memset(dist, 0, sizeof(dist));
        memset(totlen, 0, sizeof(totlen));
        memset(comp, -1, sizeof(comp));
        memset(notCyclic, 0, sizeof(notCyclic));

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                root = i;
                dfs(i, i, 0);
                if(!notCyclic[c]){
                    totlen[c] += mp[mk(i, graph[i][1])];
                }
                c++;
            }
        }
        LCAinit(n);
        printf("Case %d:\n", caseno++);
        int q;
        scanf("%d", &q);
        for(int i = 0; i < q; i++){
            scanf("%d %d", &u, &v);
            u--, v--;
            //printf("%d\n", totlen[comp[u]]);
            //printf("%d\n", LCAquery(u, v));
            if(comp[u] != comp[v]){
                printf("-1\n");
                continue;
            }
            if(notCyclic[comp[u]]){
                int l = LCAquery(u, v);
                if(l == u || l == v){
                    if(depth[u] > depth[v])
                        swap(u, v);
                    printf("%d\n", dist[v] - dist[u]);
                }
                else{
                    printf("%d\n", dist[u] + dist[v]);
                }
            }
            else{
                int l = LCAquery(u, v);
                if(l == u || l == v){
                    if(depth[u] > depth[v]){
                        swap(u, v);
                    }
                    printf("%d\n", min(dist[v] - dist[u], totlen[comp[u]] - (dist[v] - dist[u])));
                }
                else{
                    printf("%d\n", min(dist[u] + dist[v], totlen[comp[u]] - (dist[u] + dist[v])));
                }
            }
        }
        for(int i = 0; i < MAX; i++){
            graph[i].clear();
        }
    }

    return 0;
}
