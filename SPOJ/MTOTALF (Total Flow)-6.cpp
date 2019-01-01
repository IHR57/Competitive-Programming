#include <iostream>
#include <cstdio>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 100
using namespace std;

vector<int> graph[MAX];
int parent[MAX], cost[MAX][MAX], flow;
const int inf = 1<<30;

bool augmentedPath(int source, int sink)		//run ford fulkerson algorithm
{
    memset(parent, -1, sizeof(parent));
	queue<int> q;
	q.push(source);

	while(!q.empty()){
		int u = q.front();
		q.pop();

		for(int i = 0; i < graph[u].size(); i++){
			int v = graph[u][i];
			if(parent[v] == -1 && cost[u][v] > 0){
				parent[v] = u;
				q.push(v);
				if(v == sink)		//we reached to the sink from source so there is a path
					return true;
			}
		}
	}

	return false;
}

void path(int v, int source)
{
	int u = parent[v];
	flow = min(flow, cost[u][v]);

	if(source != u){
		path(u, source);
	}

	cost[u][v] -= flow;		//decreasing cost of directed graph
	cost[v][u] += flow;
}

int maxFlow(int source, int sink)
{
	int ret = 0;

	while(augmentedPath(source, sink)){			//there exists a valid path from source to sink
		flow = inf;		//initialize flow as inf
		path(sink, source);				//find the path
		ret += flow;			//add this flow
	}

	return ret;
}

int main()
{
	int test, edgeNo, weight, source, sink;
	char fst[10], snd[10];

    scanf("%d", &edgeNo);

    map<string, int> myMap;
    int idx  = 1;

    memset(cost, 0, sizeof(cost));		//initializing cost

    for(int i = 0; i < edgeNo; i++){
        scanf("%s %s %d", &fst, &snd, &weight);
        if(myMap.find(fst) == myMap.end()){
            myMap[fst] = idx++;
        }
        if(myMap.find(snd) == myMap.end()){
            myMap[snd] = idx++;
        }

        int u = myMap[fst];
        int v = myMap[snd];

        graph[u].push_back(v);
        graph[v].push_back(u);
        cost[u][v] = weight + cost[u][v];
        cost[v][u] = weight + cost[v][u];
    }
    source = myMap["A"];		//source will be A and sink will be Z
    sink = myMap["Z"];

    if(source == 0 || sink == 0)
        printf("0\n");
    else
        printf("%d\n", maxFlow(source, sink));

	return 0;
}
