//Problem ID: LightOJ - 1357 (Corrupted Friendship)
//Programmer: IQBAL HOSSAIN 	Description: DFS
//Date: 19/05/19
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

vector<int> graph[MAX];
int sbt[MAX];
ll ans = 0;

void dfs(int u, int par)
{
	for(int i = 0; i < graph[u].size(); i++){
		int v = graph[u][i];
		if(v == par)
			continue;
		dfs(v, u);
		sbt[u] += sbt[v];
	}

	sbt[u] += 1;
}

void dfs2(int u, int par)
{
	int sum = sbt[u] - 1;
	for(int i = 0; i < graph[u].size(); i++){
		int v = graph[u][i];
		if(v == par)
			continue;
		sum -= sbt[v];
		ans += (1LL * sum * sbt[v]);
		dfs2(v, u);
	}
}

int main()
{
	int test, caseno = 1, n, u, v;

	scanf("%d",  &test);

	while(test--){
		memset(sbt, 0, sizeof(sbt));
		scanf("%d", &n);
		for(int i = 0; i < n - 1; i++){
			scanf("%d %d",  &u, &v);
			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		dfs(1, -1);
		ans = 0;
		dfs2(1, -1);

		printf("Case %d: %d %lld\n", caseno++, n - 1, ans);

		for(int i = 0; i < MAX; i++)
			graph[i].clear();
	}

	return 0;
}