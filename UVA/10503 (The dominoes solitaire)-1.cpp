#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int visited[20][20], graph[20][20];
int dist[20][20];

const int INF = 1 << 28;

typedef pair<int, int> pii;

int fx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int fy[] = {1, 1, -1, 0, -1, -1, 0, 1};

int bfs(int sx, int sy, int dx, int dy)		//parameter source and destination
{
	for(int i = 0; i < 14; i++){
		for(int j = 0; j < 14; j++){
			visited[i][j] = 0;
			dist[i][j] = INF;
		}
	}

	queue<pii> q;

	q.push(pii(sx, sy));
	visited[sx][sy] = 1;		//make the source visited
	dist[sx][sy] = 0;

	while(!q.empty()){
		pii top = q.front();		//top element of queue
		q.pop();

		for(int k = 0; k < 8; k++){
			int tx = top.first + fx[k];
			int ty = top.second + fy[k];

			//check validity
			if(tx >= 0 && tx < 14 && ty >= 0 && ty < 14 && !visited[tx][ty] && graph[tx][ty]){
				visited[tx][ty] = 1;		//make it visited
				dist[tx][ty] = dist[top.first][top.second] + 1;
				q.push(pii(tx, ty));
			}
		}
	}

	return dist[dx][dy];
}

int main()
{
	int n, m, s1, s2, d1, d2, a, b;

	while(scanf("%d", &n) == 1){
		if(!n)	break;
		scanf("%d", &m);
		scanf("%d %d", &s1, &s2);		//source
		scanf("%d %d", &d1, &d2); 		//destination

		for(int i = 0; i < 14; i++){		//initialize graph
			for(int j = 0; j < 14; j++){
				graph[i][j] = 0;
			}
		}

		while(m--){
			scanf("%d %d", &a, &b);		//there is edge between a to b and b to a
			graph[a][b] = 1;
			graph[b][a] = 1;
		}
        graph[d1][d2] = 1;

		//bfs(s1, s2, d1, d2);		//call bfs

		if(bfs(s1, s2, d1, d2) == n){
			printf("YES\n");		//if we reached destination
		}
		else
			printf("NO\n");
	}

	return 0;
}
