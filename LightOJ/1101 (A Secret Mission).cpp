#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cstdlib>
#include <list>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <iomanip>
#include <stack>
#define MAX 50005
#define pb push_back
#define all(c) (c.begin(), c.end())
#define mem(a, b) memset(a, b, sizeof(a))
#define EPS 1e-10
#define PI 3.14159265358979323846
#define MOD 10000000007
#define INF 2147483647
#define mp make_pair
#define read freopen("input.txt", "r", stdin);
#define write freopen("output.txt", "w", stdout);
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
typedef vector<int> vi;
typedef vector< vector<int> >vii;
typedef vector<double> vd;
typedef vector<string> vs;
typedef long long ll;
typedef unsigned long long ull;

struct node
{
    int u, v, w;
};

bool operator<(node A, node B)
{
    return A.w < B.w;
}

int parent[MAX], depth[MAX], table[MAX][20], maxi[MAX][20], cost[MAX];
vector<node> graph;
vector<pii> graph2[MAX];

int findSet(int x)
{
    if(parent[x] == x)
        return x;
    return parent[x] = findSet(parent[x]);
}

void kruskal(int n)
{
    sort(graph.begin(), graph.end());
    for(int i = 0; i <= n; i++)
        parent[i] = i;

    for(int i = 0; i < graph.size(); i++){
        int x = findSet(graph[i].u);
        int y = findSet(graph[i].v);
        if(x != y){
            parent[x] = y;
            graph2[graph[i].u].pb(mp(graph[i].v, graph[i].w));
            graph2[graph[i].v].pb(mp(graph[i].u, graph[i].w));
        }
    }
}

void dfs(int from, int u, int dep)
{
    parent[u] = from;
    depth[u] = dep;

    for(int i = 0; i < graph2[u].size(); i++){
        int v = graph2[u][i].first;
        //cout<<v<<endl;
        int c = graph2[u][i].second;
        if(v == from)
            continue;
        cost[v] = c;
        dfs(u, v, dep+1);
    }
}

void init(int n)
{
    for(int i = 0; i < n; i++){
        table[i][0] = parent[i];
        maxi[i][0] = cost[i];
    }

    for(int j = 1; (1 << j) < n; j++){
        for(int i = 0; i < n; i++){
            if(table[i][j-1] != -1){
                table[i][j] = table[table[i][j-1]][j-1];
                maxi[i][j] = max(maxi[i][j-1], maxi[table[i][j-1]][j-1]);
            }
        }
    }
}

int maxEdge(int p, int q)
{
    int Max = -INF;

    if(depth[p] < depth[q])
        swap(p, q);

    int lg = (int) log2(depth[p]) + 1;

    for(int i = lg; i >= 0; i--){
        if(depth[p] - (1<<i) >= depth[q]){
            Max = max(Max, maxi[p][i]);
            p = table[p][i];
        }
    }

    if(p == q)
        return Max;

    for(int i = lg; i >= 0; i--){
        if(table[p][i] != -1 && table[p][i] != table[q][i]){
            Max = max(Max, max(maxi[p][i], maxi[q][i]));
            p = table[p][i];
            q = table[q][i];
        }
    }

    Max = max(Max, max(cost[p], cost[q]));

    return Max;
}

int main()
{
    //read; write;
    int test, caseNo = 1, nodeNo, edgeNo, a, b, c, q;

    scanf("%d", &test);
    while(test--){
        scanf("%d %d", &nodeNo, &edgeNo);
        while(edgeNo--){
            scanf("%d %d %d", &a, &b, &c);
            a--, b--;
            node temp;
            temp.u = a, temp.v = b, temp.w = c;
            graph.pb(temp);
        }

        kruskal(nodeNo);      //build MST from given graph

        mem(parent, -1);
        mem(table, -1);
        mem(maxi, 0);
        mem(depth, 0);
        mem(cost, 0);

        dfs(0, 0, 0);       //run dfs from builded graph
        init(nodeNo);        //initialize sparse table

        int q;

        scanf("%d", &q);
        printf("Case %d:\n", caseNo++);
        for(int i = 0; i < q; i++){
            scanf("%d %d", &a, &b);
            a--, b--;
            printf("%d\n", maxEdge(a, b));
        }

        graph.clear();
        for(int i = 0; i < MAX; i++){
            graph2[i].clear();
        }
    }

    return 0;
}
