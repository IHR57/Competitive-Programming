#include <bits/stdc++.h>
#define MAX 210
#define pb push_back
using namespace std;

vector<int> graph[MAX];
int capacity[MAX][MAX], parent[MAX], flow;
const int inf = 1<<28;

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
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int vertex, wire, source, sink, test, caseNo = 1;
	int u, v, w;

    scanf("%d", &test);

	while(test--){
        scanf("%d %d", &vertex, &wire);

        source = 1, sink = 2 * vertex + 1;

		init();		//initialize

		int value;
		for(int i = 2; i < vertex; i++){
			scanf("%d", &value);
			graph[i].pb(vertex+i);
			graph[vertex+i].pb(i);
			capacity[i][vertex+i] = value;
		}

        int ans = 0;

		while(wire--){
			scanf("%d %d %d", &u, &v, &w);
            if(u > v)
                swap(u, v);
			if((u == source && v == vertex) || (u == vertex && v == source)){        //if there is direct connection from source to server
                ans += w;
			}
            else if(u == source){
                graph[source].pb(v);
                graph[v].pb(source);
                capacity[source][v] = w;
            }
            else if(v == vertex){
                graph[u+vertex].pb(sink);
                graph[sink].pb(u+vertex);
                capacity[u+vertex][sink] = w;
            }
            else{
                graph[u+vertex].pb(v);
                graph[v].pb(u+vertex);
                graph[v+vertex].pb(u);
                graph[u].pb(v+vertex);
                capacity[u+vertex][v] = w;
                capacity[v+vertex][u] = w;
            }
		}

		ans += maxFlow(source, sink);

		printf("Case %d: %d\n", caseNo++, ans);

	}

	return 0;
}
