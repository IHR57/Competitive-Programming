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

int sbt[MAX], depth[MAX];
int n, k;
vector<int> graph[MAX];

void dfs(int u, int par, int dep)
{
    depth[u] = dep;

    for(int i = 0; i < graph[u].size(); i++){
        int v = graph[u][i];
        if(v == par)
            continue;
        dfs(v, u, dep + 1);
        sbt[u] += sbt[v];
    }

    sbt[u] += 1;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n>>k;

    int u, v;
    for(int i = 0; i < n - 1; i++){
        cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    dfs(1, -1, 0);

    vector<int> vi;
    for(int i = 1; i <= n; i++){
        int temp = depth[i] - sbt[i] + 1;
        vi.pb(temp);
    }

    sort(vi.begin(), vi.end());
    reverse(vi.begin(), vi.end());

    ll sum = 0;
    for(int i = 0; i < k; i++){
        sum += (ll) vi[i];
    }

    cout<<sum<<endl;

    return 0;
}
