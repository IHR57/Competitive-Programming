#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <cstring>
#define MAX 50
using namespace std;

vector<int> graph[MAX];
int capacity[MAX][MAX], parent[MAX], flow;
const int inf = 1000;

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

	capacity[u][v] -= flow;		//residual capacity
	capacity[v][u] += flow;
	return;
}

int maxFlow(int source, int sink)
{
	int ret = 0;

	while(augmentedPath(source, sink)){
		flow = inf;		//initialize flow
		path(sink, source);		//we will find flow of a path
		ret += flow;			//we add this flow
	}

	return ret;
}

int main()
{
	int test, caseNo = 1, tShirt, participants;
	char firstChoice[10], secondChoice[10];

	scanf("%d", &test);

	while(test--){
		scanf("%d %d", &tShirt, &participants);
		//number of tShirt of each category will be tShirt / 6

		init();
		for(int i = 1; i <= 6; i++){ 	//there are six category
			graph[0].push_back(i);		//linking each category with source node 0
			graph[i].push_back(0);
			capacity[0][i] = tShirt / 6;
		}

		map<string, int> myMap;
		int idx = 1;
		for(int i = 1; i <= participants; i++){
			scanf("%s %s", firstChoice, secondChoice);
			if(myMap.find(firstChoice) == myMap.end()){		//mapping category
				myMap[firstChoice] = idx++;
			}
			if(myMap.find(secondChoice) == myMap.end()){
				myMap[secondChoice] = idx++;
			}
			int u = myMap[firstChoice];
			int v = myMap[secondChoice];

			graph[u].push_back(i + 6);		//linking participants with category they choose
			graph[i+6].push_back(u);
			graph[v].push_back(i + 6);
			graph[i+6].push_back(v);
			capacity[u][i+6] = inf;
			capacity[v][i+6] = inf;
		}

		int sink = 40;

		for(int i = 1; i <= participants; i++){		//linking each participants with sink
			graph[i+6].push_back(sink);
			graph[sink].push_back(i + 6);
			capacity[i+6][sink] = 1;
		}

		int ans = maxFlow(0, sink);

		if(ans == participants)
            printf("YES\n");
        else
            printf("NO\n");
	}

	return 0;
}
