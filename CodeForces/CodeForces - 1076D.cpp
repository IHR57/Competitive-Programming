//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define mem(a, b) (memset(a, b, sizeof(a)))
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define INF 2147483647
#define MOD 1000000009
#define MAX 300005
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<ll, int> ii;
typedef pair<int, ii> pii;
typedef vector<ii> vii;
typedef priority_queue<ii,vector<ii>,greater<ii> > PQ;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

struct Edge
{
    int dest, cost, idx;
};

vector<Edge> graph[MAX];
ll dist[MAX];
bool vis[MAX];
int par[MAX];
PQ pq;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m, k;

    cin>>n>>m>>k;

    for(int i = 1; i <= m; i++) {
        int u, v, w;
        cin>>u>>v>>w;
        graph[u].pb(Edge{v, w, i});
        graph[v].pb(Edge{u, w, i});
    }

    for(int i = 0; i <= n; i++)
        dist[i] = 3e15;
    dist[1] = 0;

    pq.push(mk(0, 1));

    vector<int> ans;

    while(!pq.empty()) {
        int u = pq.top().ss;
        pq.pop();

        if(vis[u])
            continue;
        vis[u] = 1;

        if(par[u])
            ans.pb(par[u]);

        for(int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i].dest;
            if((graph[u][i].cost + dist[u]) < dist[v]) {
                dist[v] = graph[u][i].cost + dist[u];
                par[v] = graph[u][i].idx;
                pq.push(mk((graph[u][i].cost + dist[u]), v));
            }
        }
    }

    if(ans.size() > k)
        ans.resize(k);

    cout<<ans.size()<<endl;
    for(int i = 0; i < ans.size(); i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}
