/*
Template for vjudge.net

	Author: Iqbal Hossain Rasel
	CodeForces: The_Silent_Man
	AtCoder   : IHR57
	TopCoder  : IHR57

*/
//Date: 19/08/19
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define pi 3.1415926535897932384
#define INF 2147483647
#define EPS 1e-8
#define MOD 1000000007
#define MAX 100005
using namespace std;

typedef long long ll;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(ll mask, ll pos){return (bool)(mask & (1LL<<pos));}

int bit[70], idx = 1;
int dist[300], vis[300];
ll arr[MAX];
vector<ll> v[70];
vector<int> graph[MAX];
vector<pair<int, int> > edge;

void bfs(int s, int d)
{
    for(int i = 0; i < 300; i++){
        dist[i] = INF;
    }
    memset(vis, 0, sizeof(vis));

    dist[s] = 0;
    vis[s] = 1;
    queue<int> q;
    q.push(s);

    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i = 0; i < graph[u].size(); i++){
            int v = graph[u][i];
            if(!vis[v]){
                vis[v] = 1;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
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
    int n;

    cin>>n;
    map<ll, int> MP;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
        for(int j = 0; j <= 63; j++){
            if(check(arr[i], j)){
                bit[j]++;
                v[j].pb(arr[i]);
            }
        }
    }

    bool flag = false;
    for(int i = 0; i <= 63; i++){
        if(bit[i] >= 3){
            cout<<3<<endl;
            return 0;
        }
        if(bit[i] >= 2)
            flag = true;
    }

    if(!flag){
        cout<<-1<<endl;
        return 0;
    }

    for(int i = 0; i <= 63; i++){
        if(v[i].size() >= 2){
            if(MP[v[i][0]] == 0){
                MP[v[i][0]] = idx++;
            }
            if(MP[v[i][1]] == 0){
                MP[v[i][1]] = idx++;
            }
            edge.pb(mp(MP[v[i][0]], MP[v[i][1]]));
        }
    }

    int res = 1e8;
    for(int i = 0; i < edge.size(); i++){
        for(int j = 0; j < edge.size(); j++){
            if(i == j)
                continue;
            if((edge[j].ff == edge[i].ff && edge[j].ss == edge[i].ss) || (edge[j].ff == edge[i].ss && edge[j].ss == edge[i].ff))
                continue;
            graph[edge[j].ff].pb(edge[j].ss);
            graph[edge[j].ss].pb(edge[j].ff);
        }
        bfs(edge[i].ff, edge[i].ss);
        if(dist[edge[i].ss] < INF){
            int temp = dist[edge[i].ss] + 1;
            if(temp >= 3 && temp < res){
                res = temp;
            }
        }
        for(int i = 0; i < 300; i++)
            graph[i].clear();
    }

    (res == 1e8) ? cout<<-1<<endl : cout<<res<<endl;

    return 0;
}
