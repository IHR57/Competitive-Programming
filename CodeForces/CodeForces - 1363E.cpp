//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define mem(a, b) (memset(a, b, sizeof(a)))
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define INF 2147483647
#define MOD 1000000007
#define MAX 200005
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> pii;
typedef vector<ii> vii;
typedef priority_queue<int,vector<int>,greater<int> > PQ;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

vector<int> graph[MAX];
int cost[MAX], b[MAX], c[MAX];
int trans[MAX][2];
ll ans;

void dfs(int u, int par, int MinCost)
{
    if(b[u] != c[u]) {
        if(b[u] == 1) {
            trans[u][0] += 1;
        }
        else
            trans[u][1] += 1;
    }

    for(int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        if(v == par)
            continue;
        dfs(v, u, min(MinCost, cost[u]));
        trans[u][0] += trans[v][0];
        trans[u][1] += trans[v][1];
    }

    if(cost[u] < MinCost) {
        int tm = min(trans[u][0], trans[u][1]);
        ans += 1LL * 2 * tm * cost[u];
        trans[u][0] -= tm;
        trans[u][1] -= tm;
    }

}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;

    cin>>n;

    for(int i = 1; i <= n; i++) {
        cin>>cost[i]>>b[i]>>c[i];
    }

    for(int i = 1; i < n; i++) {
        int u, v;
        cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    dfs(1, -1, 2e9);

    if(trans[1][0] >= 1 || trans[1][1] >= 1) {
        cout<<-1<<endl;
        return 0;
    }

    cout<<ans<<endl;

    return 0;
}

