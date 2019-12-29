#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define INF 2147483647
#define MOD 1000000007
#define MAX 200005
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> pii;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int parent[MAX], Rank[MAX];
vector<pii> edge;
vector<ii> query;
ll res, ans[MAX];

int getParent(int v)
{
    if(v == parent[v])
        return v;
    return parent[v] = getParent(parent[v]);
}

void unionSet(int a, int b)
{
    int u = getParent(a);
    int v = getParent(b);

    if(Rank[u] < Rank[v])
        swap(u, v);

    parent[v] = u;
    res -= (1LL * Rank[u] * (Rank[u] - 1)) / 2;
    res -= (1LL * Rank[v] * (Rank[v] - 1)) / 2;
    Rank[u] += Rank[v];
    res += (1LL * Rank[u] * (Rank[u] - 1)) / 2;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, q, u, v, w;

    cin>>n>>q;
    for(int i = 0; i < n - 1; i++){
        cin>>u>>v>>w;
        edge.pb(mp(w, mp(u, v)));
    }

    for(int i = 0; i < q; i++){
        cin>>u;
        query.pb(mp(u, i));
    }

    sort(edge.begin(), edge.end());
    sort(query.begin(), query.end());

    for(int i = 1; i <= n; i++){
        parent[i] = i;
        Rank[i] = 1;
    }

    int idx = 0;
    for(int i = 0; i < q; i++){
        while(idx < n - 1 && edge[idx].ff <= query[i].ff){
            unionSet(edge[idx].ss.ff, edge[idx].ss.ss);
            idx++;
        }
        ans[query[i].ss] = res;
    }

    for(int i = 0; i < q; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;


    return 0;
}
