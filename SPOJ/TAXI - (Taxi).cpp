#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define MAX 610
#define pb push_back
using namespace std;

typedef pair<int, int> pii;
vector<int> graph[MAX];
int passengers, taxi, Left[MAX], Right[MAX], visited[MAX];

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

int MBM()
{
	int count = 0;
	memset(Left, -1, sizeof(Left));
	memset(Right, -1, sizeof(Right));

	for(int i = 0; i < passengers; i++){
		memset(visited, 0, sizeof(visited));
		if(kuhn(i))
			count++;
	}

	return count;
}

int main()
{
	int velocity, timeLimit, test;
	int x, y;

	scanf("%d", &test);

	while(test--){
		scanf("%d %d %d %d", &passengers, &taxi, &velocity, &timeLimit);
		pii temp[MAX];

		for(int i = 0; i < passengers + taxi; i++){
			scanf("%d %d", &x, &y);
			temp[i] = make_pair(x, y);
		}

		for(int i = 0; i < passengers; i++){
			for(int j = passengers; j < taxi + passengers; j++){
				int dist = abs(temp[i].first - temp[j].first) + abs(temp[i].second - temp[j].second);		//distance between passengers and taxi
				int t = (dist * 200) / velocity;
				if(t <= timeLimit){		//if the taxi can reach to the passengers with the given time limit;
					graph[i].pb(j);
				}
			}
		}

		int ans = MBM();
		printf("%d\n", ans);

		for(int i = 0; i < MAX; i++)
			graph[i].clear();
	}

	return 0;
}
