/*
Template for vjudge.net

	Author: Iqbal Hossain Rasel
	CodeForces: The_Silent_Man
	AtCoder   : IHR57
	TopCoder  : IHR57

*/
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
#define MAX 200005
using namespace std;

typedef long long ll;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int n, m;
vector<int> graph[MAX];
int dist[MAX], vis[MAX];

void bfs(int s)
{
	vis[s] = 1;
	dist[s] = 0;
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
    int test;

    cin>>test;

    while(test--){
    	cin>>n>>m;
    	for(int i = 0; i <= n; i++){
    		vis[i] = 0;
    		graph[i].clear();
    	}
    	for(int i = 0; i < m; i++){
    		int u, v;
    		cin>>u>>v;
    		graph[u].pb(v);
    		graph[v].pb(u);
    	}

    	bfs(1);
    	int x = *max_element(dist + 1, dist + n + 1);
    	int d1 = 0, d2 = 0;
    	for(int i = 1; i <= n; i++){
    		d1 += (dist[i] % 2 == 0);
    		d2 += (dist[i] % 2 == 1);
    	}

    	if(d1 <= d2){
    		cout<<d1<<endl;
    		for(int i = 1; i <= n; i++){
    			if(dist[i] % 2 == 0)
    				cout<<i<<" ";
    		}
    		cout<<endl;
    	}
    	else{
    		cout<<d2<<endl;
    		for(int i = 1; i <= n; i++){
    			if(dist[i] & 1)
    				cout<<i<<" ";
    		}
    		cout<<endl;
    	}
    }

    return 0;
}
