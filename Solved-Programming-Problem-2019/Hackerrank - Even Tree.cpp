//Date: 04/11/19
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
#define MAX 105
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int n, cnt = 0;
vector<int> graph[MAX];
int sbt[MAX];

void dfs(int u, int par)
{
    for(int i = 0; i < graph[u].size(); i++){
        int v = graph[u][i];
        if(v == par)
            continue;
        dfs(v, u);
        sbt[u] += sbt[v];
        if(sbt[v] % 2 == 0){
            cnt++;
        }
    }

    sbt[u] += 1;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    int m, u, v;

    cin>>n>>m;

    for(int i = 0; i < m; i++){
        cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    dfs(1, -1);

    cout<<cnt<<endl;

    return 0;
}