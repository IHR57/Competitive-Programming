#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define MAX 300
#define pb push_back
using namespace std;

vector<int> graph[MAX];
int visited[MAX], Left[MAX], Right[MAX], n;

bool kuhn(int u)
{
	for(int i = 0; i < graph[u].size(); i++){
		int v = graph[u][i];
		if(visited[v])
			continue;
		visited[v] = 1;
		if(Right[v] == -1 || kuhn(Right[v])){
			Right[v] = u;
			Left[u] = v;
			return true;
		}
	}

	return false;
}

int bipartiteMatching()
{
	int count = 0;
	memset(Left, -1, sizeof(Left));
	memset(Right, -1, sizeof(Right));

	for(int i = 0; i < 120; i++){
		memset(visited, 0, sizeof(visited));
		if(kuhn(i))
			count++;
	}

	return count;
}
int main()
{
	int test, x, y;

	scanf("%d", &test);

	while(test--){
		scanf("%d", &n);		//number of missing locations
		for(int i = 0; i < n; i++){
			scanf("%d %d", &x, &y);
			graph[x].pb(y+120);
		}

		int ans = bipartiteMatching();

		printf("%d\n", ans);

		for(int i = 0; i < MAX; i++)
			graph[i].clear();
	}

	return 0;
}
