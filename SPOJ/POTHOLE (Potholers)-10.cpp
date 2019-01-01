#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define MAX 205
using namespace std;

int cost[MAX][MAX], parent[MAX], visited[MAX], nodeNo;
vector<int> graph[MAX];
const int inf = 1<<29;

void init()
{
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++)
            cost[i][j] = 0;
    }

    for(int i = 0; i < MAX; i++)
        graph[i].clear();
}
bool augmentedPath(int source, int sink)
{
	memset(parent, -1, sizeof(parent));
	memset(visited, 0, sizeof(visited));

	queue<int> q;
	q.push(source);

	while(!q.empty()){
		int u = q.front();
		q.pop();

        if(u == sink)
            break;
		for(int i = 1; i <= nodeNo; i++){
            if(!visited[i] && cost[u][i] > 0){
                q.push(i);
                parent[i] = u;
                visited[i] = true;
            }
		}
	}

	return (visited[sink] == true);
}

void path(int v, int source)
{
	int u = parent[v];
	if(source != u)
		path(u, source);
	cost[u][v]--;
	cost[v][u]++;

	return;
}

int maxFlow(int source, int sink)
{
	int count = 0;
	while(augmentedPath(source, sink)){
		path(sink, source);
		count++;
	}

	return count;		//return number of disjoint augmented path found;
}

int main()
{
	int test, conn;		//conn -- number of connection of the node
	int v;

	scanf("%d", &test);

	while(test--){
		scanf("%d", &nodeNo);

        init();
		for(int i = 1; i < nodeNo; i++){
			scanf("%d", &conn);
			while(conn--){
				scanf("%d", &v);
				graph[i].push_back(v);
				if(i == 1 || v == nodeNo)
                    cost[i][v] = 1;
                else
                    cost[i][v] = 10000;
			}
		}

		int ans = maxFlow(1, nodeNo);

		printf("%d\n", ans);
	}

	return 0;
}
