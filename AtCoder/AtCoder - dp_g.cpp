/*
Template for vjudge.net

	Author: Iqbal Hossain Rasel
	CodeForces: The_Silent_Man
	AtCoder   : IHR57
	TopCoder  : IHR57

*/
//Problem Link: https://atcoder.jp/contests/dp/tasks
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
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int dist[MAX], vis[MAX];
vector<int> graph[MAX];

void dfs(int u)
{
    vis[u] = 1;
    int mx = 0;
    if(graph[u].size() == 0){
        dist[u] += 1;
    }
    for(int i = 0; i < graph[u].size(); i++){
        int v = graph[u][i];
        if(!vis[v]){
            dfs(v);
        }
        dist[u] = max(dist[u], 1 + dist[v]);
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifdef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif
    int n, m, u, v;
    cin>>n>>m;

    for(int i = 0; i < m; i++){
        cin>>u>>v;
        graph[u].pb(v);
    }

    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            dfs(i);
        }
    }

    cout<<*max_element(dist + 1, dist + n + 1) - 1<<endl;

    return 0;
}
