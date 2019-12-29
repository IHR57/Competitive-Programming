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

set<int> s;
vector<int> graph[MAX];
int vis[MAX], maxNode;

void dfs(int u)
{
    vis[u] = 1;
    if(s.count(u))
        s.erase(u);
    maxNode = max(maxNode, u);

    for(int i = 0; i < graph[u].size(); i++){
        int v = graph[u][i];
        if(!vis[v]){
            dfs(v);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;

    cin>>n>>m;

    for(int i = 1; i <= n; i++)
        s.insert(i);

    for(int i = 0; i < m; i++){
        int u, v;
        cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    ll ans = 0;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            maxNode = 0;
            dfs(i);
            int cnt = 0;
            if(maxNode == i || maxNode == i + 1)
                continue;
            //cout<<maxNode<<endl;
            while(true){
                if(!s.empty()){
                    int t = *s.begin();
                    if(t > i && t < maxNode && !vis[t]){
                        dfs(t);
                        cnt++;
                    }
                    if(t >= maxNode)
                        break;
                }
                else{
                    break;
                }
            }
            ans += (ll) cnt;
        }
    }

    cout<<ans<<endl;

    return 0;
}
