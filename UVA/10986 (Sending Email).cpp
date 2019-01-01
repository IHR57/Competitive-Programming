#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 20004
using namespace std;

vector<int> graph[MAX], cost[MAX];
int dist[MAX];
//int cost[MAX][MAX];
const int INF = 1 << 28;

struct data
{
	int node, dist;
};

bool operator<(data A, data B)
{
	return A.dist > B.dist;
}

int dijkstra(int source, int destination)
{
	for(int i = 0; i < MAX; i++){			//initialize all distance as infinity
		dist[i] = INF;
	}

	priority_queue<data> pq;

	data u, v;

	u.node = source, u.dist = 0;
	pq.push(u);						//push the source node
	dist[source] = 0;			//distance of the source node

	while(!pq.empty()){
		u = pq.top();
		pq.pop();
		int ucost = dist[u.node];

		for(int i = 0; i < graph[u.node].size(); i++){
			v.node = graph[u.node][i];				//connected node
			v.dist = cost[u.node][i] + ucost;		//distance from source

			if(v.dist < dist[v.node]){		//if we find less distance from previous
				dist[v.node] = v.dist;
				pq.push(v);
			}
		}
	}

	return dist[destination];
}

int main()
{
	int test, n, m, source, destination, cases = 1;
	int u, v, weight;

	scanf("%d", &test);

	while(test--){
		scanf("%d %d %d %d", &n, &m, &source, &destination);

		for(int i = 0; i < m; i++){
			scanf("%d %d %d", &u, &v, &weight);
			graph[u].push_back(v);
			graph[v].push_back(u);      //bidirectional graph
			cost[u].push_back(weight);      //cost
			cost[v].push_back(weight);

		}

		int result = dijkstra(source, destination);

		if(result == INF)
			printf("Case #%d: unreachable\n", cases++);
		else
			printf("Case #%d: %d\n", cases++, result);

        for(int i = 0; i < n; i++){
            graph[i].clear();
            cost[i].clear();
        }
	}

	return 0;
}
