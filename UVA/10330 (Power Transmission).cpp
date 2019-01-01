#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define MAX 255
#define pb push_back
using namespace std;

vector<int> graph[MAX];
int parent[MAX], capacity[MAX][MAX], flow;
const int inf = 200000;

void init()
{
	memset(capacity, 0, sizeof(capacity));
	for(int i = 0; i < MAX; i++)
		graph[i].clear();
}

bool augmentedPath(int source, int sink)
{
	memset(parent, -1, sizeof(parent));

	queue<int> q;
	q.push(source);

	while(!q.empty()){
		int u = q.front();
		q.pop();

		for(int i = 0; i < graph[u].size(); i++){
			int v = graph[u][i];
			if(parent[v] == -1 && capacity[u][v] > 0){
				parent[v] = u;
				q.push(v);
				if(v == sink)
					return true;
			}
		}
	}

	return false;
}

void path(int v, int source)
{
	int u = parent[v];
	flow = min(flow, capacity[u][v]);

	if(u != source)
		path(u, source);

	capacity[u][v] -= flow;
	capacity[v][u] += flow;
	return;
}

int maxFlow(int source, int sink)
{
	int ret = 0;

	while(augmentedPath(source, sink)){
		flow = inf;
		path(sink, source);
		ret += flow;
	}

	return ret;
}

int main()
{
	int u, v, w, cost[MAX], regulator, link;

	while(scanf("%d", &regulator) == 1){
		init();
		for(int i = 1; i <= regulator; i++){
			scanf("%d", &cost[i]);
		}

		scanf("%d", &link);		//number of edge;

		for(int i = 1; i <= regulator; i++){
			//scanf("%d %d %d", &u, &v, &w);
			graph[i].pb(i+100);		//as vertex capacity is given we have to split the node
			graph[i+100].pb(i);
			capacity[i][i+100] = cost[i];		//new edge capacity will be the node capacity
		}

		for(int i = 1; i <= link; i++){
			scanf("%d %d %d", &u, &v, &w);
			graph[u+100].pb(v);
			graph[v].pb(u+100);
			capacity[u+100][v] = w;
		}

		int sources, sinks, x, supersink = 230;

		scanf("%d %d", &sources, &sinks);

		for(int i = 1; i <= sources; i++){
			scanf("%d", &x);
			graph[0].pb(x);		//connect this node with supersource 0
			graph[x].pb(0);
			capacity[0][x] = inf;
		}

		for(int i = 1; i <= sinks; i++){		//connect with supersink
			scanf("%d", &x);
			graph[x+100].pb(supersink);
			graph[supersink].pb(x+100);
			capacity[x+100][supersink] = inf;
		}

		int ans = maxFlow(0, supersink);
		printf("%d\n", ans);
	}

	return 0;
}
