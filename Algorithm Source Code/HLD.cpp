//Problem Link: https://www.spoj.com/problems/QTREE/
#include <bits/stdc++.h>
#define MAX 100005
#define pb push_back
#define INF 2147483647
using namespace std;

const int LG = 16;

//chainHead - starting node of a chain
//chainIdx - index of a node in a chain
//idxInBase - index of a node in a base array
int chainHead[MAX], chainNo, chainIdx[MAX], arr[MAX], idxInBase[MAX], ptr;
int parent[LG][MAX], sbt[MAX], otherEnd[MAX], depth[MAX];
int st[4*MAX], qt[4*MAX];
vector<int> graph[MAX], idxx[MAX], costs[MAX];

void dfs(int u, int par, int _depth = 0)
{
    parent[0][u] = par;
    depth[u] = _depth;
    sbt[u] = 1;

    for(int i = 0; i < graph[u].size(); i++){
        int v = graph[u][i];
        if(v != par){
            otherEnd[idxx[u][i]] = v;
            dfs(v, u, _depth + 1);
            sbt[u] += sbt[v];
        }
    }
}

void build(int cur, int s, int e)
{
    if(s == e - 1){
        st[cur] = arr[s];
        return;
    }
    int m = (s + e) >> 1;
    build(cur * 2, s, m);
    build(cur * 2 + 1, m, e);
    st[cur] = max(st[cur*2], st[cur*2+1]);
}

void update(int cur, int s, int e, int x, int val)
{
    if(s > x || e <= x)
        return;
    if(s == x && s == e - 1){
        st[cur] = val;
        return;
    }
    int m = (s + e) >> 1;
    update(cur * 2, s, m, x, val);
    update(cur * 2 + 1, m, e, x, val);
    st[cur] = max(st[cur*2], st[cur*2+1]);
}

void query_tree(int cur, int s, int e, int l, int r)
{
    if(s >= r || e <= l){
        qt[cur] = -1;
        return;
    }

    if(s >= l && e <= r){
        qt[cur] = st[cur];
        return;
    }

    int m = (s + e) >> 1;
    query_tree(cur*2, s, m, l, r);
    query_tree(cur*2+1, m, e, l, r);
    qt[cur] = max(qt[cur*2], qt[cur*2+1]);
}

int query_up(int u, int v)
{
    if(u == v)
        return 0;
    int uchain = chainIdx[u], vchain = chainIdx[v], ans = -1;
    while(true){
        uchain = chainIdx[u];
        if(uchain == vchain){   //both are in same chain
            if(u == v)
                break;
            query_tree(1, 0, ptr, idxInBase[v] + 1, idxInBase[u] + 1);
            if(qt[1] > ans)
                ans = qt[1];
            break;
        }
        query_tree(1, 0, ptr, idxInBase[chainHead[uchain]], idxInBase[u] + 1);
        if(qt[1] > ans)
            ans = qt[1];
        u = chainHead[uchain];
        u = parent[0][u];
    }

    return ans;
}

void HLD(int u, int cost, int par)
{
    if(chainHead[chainNo] == -1){
        chainHead[chainNo] = u;     //assign chain head
    }

    chainIdx[u] = chainNo;
    idxInBase[u] = ptr;
    arr[ptr++] = cost;      //base array

    int sc = -1, ncost;
    for(int i = 0; i < graph[u].size(); i++){
        int v = graph[u][i];
        if(v != par){
            if(sc == -1 || sbt[sc] < sbt[v]){       //maximum sub-tree
                sc = v;
                ncost = costs[u][i];
            }
        }
    }
    if(sc != -1)        //expand the current chain
        HLD(sc, ncost, u);

    for(int i = 0; i < graph[u].size(); i++){   //new chain for each normal node
        int v = graph[u][i];
        if(v != par){
            if(v != sc){
                chainNo++;
                HLD(v, costs[u][i], u);
            }
        }
    }
}

void initLCA(int n)
{
    for(int i = 1; i < LG; i++){
        for(int j = 0; j < n; j++){
            if(parent[i-1][j] != -1)
                parent[i][j] = parent[i-1][parent[i-1][j]];
        }
    }
}

int LCA(int u, int v)
{
    if(depth[v] > depth[u])
        swap(u, v);

    for(int i = LG - 1; i >= 0; i--){
        if(depth[u] - (1 << i) >= depth[v]){
            u = parent[i][u];
        }
    }
    if(u == v)
        return u;

    for(int i = LG - 1; i >= 0; i--){
        if(parent[i][u] != parent[i][v]){
            u = parent[i][u];
            v = parent[i][v];
        }
    }

    return parent[0][u];
}

void change(int i, int v)
{
    int u = otherEnd[i];
    update(1, 0, ptr, idxInBase[u], v);
}

int query(int u, int v)
{
    int lca = LCA(u, v);
    int ans = query_up(u, lca);
    ans = max(ans, query_up(v, lca));
    return ans;
}

int main()
{
    int test;

    scanf("%d", &test);

    while(test--){
        ptr = 0;
        int n;
        scanf("%d", &n);

        for(int i = 0; i < n; i++){
            graph[i].clear();
            costs[i].clear();
            idxx[i].clear();
            chainHead[i] = -1;
            for(int j = 0; j < LG; j++){    //initializing parent for LCA
                parent[j][i] = -1;
            }
        }

        for(int i = 0; i < n - 1; i++){
            int u, v, c;
            scanf("%d %d %d",  &u, &v, &c);
            u--, v--;
            graph[u].pb(v);
            graph[v].pb(u);
            costs[u].pb(c);
            costs[v].pb(c);
            idxx[u].pb(i);
            idxx[v].pb(i);
        }

        chainNo = 0;
        dfs(0, -1);
        HLD(0, -1, -1);
        build(1, 0, ptr);
        initLCA(n);

        while(true){
            char str[105];
            scanf("%s", str);

            if(str[0] == 'D')
                break;
            int a, b;
            scanf("%d %d", &a, &b);
            if(str[0] == 'Q'){
                printf("%d\n", query(a - 1, b - 1));
            }
            else{
                change(a - 1, b);
            }
        }

    }
    return 0;
}
