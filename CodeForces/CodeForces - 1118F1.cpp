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
#define MAX 300005
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> pii;
typedef vector<ii> vii;
typedef priority_queue<int,vector<int>,greater<int> > PQ;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}
  
int color[MAX], sbt[MAX][2];
vector<int> graph[MAX];
vector<ii> edges;
int red, blue, ans;

void dfs(int u, int par)
{
    if(color[u] == 1)
        sbt[u][0] = 1;
    if(color[u] == 2)
        sbt[u][1] = 1;

    for(int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        if(v == par)
            continue;
        dfs(v, u);
        sbt[u][0] += sbt[v][0];
        sbt[u][1] += sbt[v][1];

        if(sbt[v][0] > 0 && sbt[v][1] > 0)
            continue;
        if((red - sbt[v][0]) > 0 && (blue - sbt[v][1]) > 0)
            continue;
        ans++;
    }

}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
     
    int n;

    cin>>n;

    for(int i = 1; i <= n; i++) {
        cin>>color[i];
        if(color[i] == 1)
            red++;
        else if(color[i] == 2)
            blue++;
    }

    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    dfs(1, -1);

    cout<<ans<<endl;

    return 0;
}


