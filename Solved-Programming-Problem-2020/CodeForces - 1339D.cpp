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
#define MAX 100005
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
int color[MAX];
set<int> s;

int n;
int minAns, maxAns;

void dfs(int u, int par, int dis)
{
    int cnt = 0;
    for(int i = 0; i < graph[u].size(); i++){
        int v = graph[u][i];
        if(v == par)
            continue;
        color[v] = !color[u];
        dfs(v, u, dis + 1);
        if(graph[v].size() == 1)
            cnt++;

    }
    if(cnt > 1){
        maxAns -= cnt - 1;
    }
    if(graph[u].size() == 1){
        s.insert(color[u]);
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin>>n;

    int u, v;

    for(int i = 0; i < n - 1; i++){
        cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    int root;
    for(int i = 1; i <= n; i++){
        if(graph[i].size() >= 2)
            root = i;
    }

    maxAns = n - 1;
    dfs(root, -1, 0);

    minAns = (s.size() == 1) ? 1 : 3;

    cout<<minAns<<" "<<maxAns<<endl;

    return 0;
}
