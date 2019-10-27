//Tag: MO on Path
//Date: 15/10/19
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
#define MAX 300005
using namespace std;
 
typedef long long ll;
typedef pair<int, int> ii;
 
int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

vector<int> graph[MAX];
int st[MAX], en[MAX], ID[MAX], parent[MAX][20], depth[MAX];
int a[MAX], b[MAX], cnt = 0, n, m, res = 0, vis[MAX], ans[MAX], counter[MAX];
const int Block = 555;

struct query
{
    int id, l, r, lca;
    bool operator < (const query& rhs)
    {
        return (l / Block == rhs.l / Block) ? r < rhs.r : (l / Block) < (rhs.l / Block);
    }
}q[MAX];

void dfs(int u, int par)
{
    st[u] = ++cnt;
    ID[cnt] = u;

    for(int i = 0; i < graph[u].size(); i++){
        int v = graph[u][i];
        if(v == par)
            continue;
        parent[v][0] = u;
        depth[v] = depth[u] + 1;
        dfs(v, u);
    }

    en[u] = ++cnt;
    ID[cnt] = u;
}

void LCAinit()
{
    memset(parent, -1, sizeof(parent));

    dfs(1, -1);

    for(int j = 1; (1<<j) <= n; j++){
        for(int i = 1; i <= n; i++){
            if(parent[i][j-1] != -1){
                parent[i][j] = parent[parent[i][j-1]][j-1];
            }
        }
    }
}

int LCA(int u, int v)
{
    if(depth[u] > depth[v])
        swap(u, v);
    for(int i = 18; i >= 0; i--){
        if(depth[v] - (1 << i) >= depth[u])
            v = parent[v][i];
    }
    if(u == v)
        return u;

    for(int i = 18; i >= 0; i--){
        if(parent[u][i] != parent[v][i]){
            u = parent[u][i];
            v = parent[v][i];
        }
    }

    return parent[u][0];
}

void check(int x)
{
    if(vis[x] && (--counter[a[x]] == 0)){
        res--;
    }
    else if((!vis[x] && counter[a[x]]++ == 0)){
        res++;
    }
    vis[x] ^= 1;
}

void compute()
{
    int curL = q[0].l, curR = q[0].l - 1;

    for(int i = 0; i < m; i++){
        while(curL < q[i].l)
            check(ID[curL++]);
        while(curL > q[i].l)
            check(ID[--curL]);
        while(curR < q[i].r)
            check(ID[++curR]);
        while(curR > q[i].r)
            check(ID[curR--]);

        int u = ID[curL], v = ID[curR];
        if(q[i].lca != u && q[i].lca != v){
            check(q[i].lca);
        }
        ans[q[i].id] = res;
        if(q[i].lca != u && q[i].lca != v){
            check(q[i].lca);
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
    int u, v;
    
    scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        b[i] = a[i];
    }

    sort(b + 1, b + n + 1);

    //mapping value
    for(int i = 1; i <= n; i++){
        a[i] = lower_bound(b + 1, b + n + 1, a[i]) - b;
    }

    for(int i = 0; i < n - 1; i++){
        scanf("%d %d", &u, &v);
        graph[u].pb(v);
        graph[v].pb(u);
    }
    
    parent[1][0] = 1;
    LCAinit();

    for(int i = 0; i < m; i++){
        scanf("%d %d", &u, &v);
        if(st[u] > st[v])
            swap(u, v);
        q[i].lca = LCA(u, v);
        if(q[i].lca == u)
            q[i].l = st[u], q[i].r = st[v];
        else
            q[i].l = en[u], q[i].r = st[v];
        q[i].id = i;
    }

    sort(q, q + m);
    compute();

    for(int i = 0; i < m; i++){
        printf("%d\n", ans[i]);
    }

    return 0;
}