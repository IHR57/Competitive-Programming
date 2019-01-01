#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cmath>
#include <queue>
#define MAX 250
#define pb push_back
using namespace std;

typedef pair<int, int> pii;
int n, capacity[MAX][MAX], parent[MAX], flow, extra[MAX][MAX];
vector<int> graph[MAX];
const int inf = 1<<29;

void init()		//initialize adjacency list  and capacity
{
	for(int i = 0; i < MAX; i++){
		for(int j = 0; j < MAX; j++)
			capacity[i][j] = 0;
		graph[i].clear();
	}
}

double calculateDistance(int x1, int y1, int x2, int y2)        //distance between two point
{
	return (double) sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
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
			if(parent[v] == -1 && (capacity[u][v] - extra[u][v])> 0){
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
	flow = min(flow, capacity[u][v] - extra[u][v]);

	if(u != source)
		path(u, source);

    //we need update extra array because maxFlow will be called multiple time
    //so we have to keep capacity array unchanged
	extra[u][v] += flow;
	extra[v][u] -= extra[u][v];
	return;
}

int maxFlow(int source, int sink)
{
    for(int i = 0; i <= 2 * n + 1; i++){
        for(int j = 0; j <= 2 * n + 1; j++){
            extra[i][j] = 0;
        }
    }

	int ret = 0;
	while(augmentedPath(source, sink)){
		flow = inf + 1;
		path(sink, source);
		ret += flow;
	}

    //cout<<ret<<endl;
	return ret;
}

int main()
{
	int test, x, y, source, totalPenguine, penguine, cap;
	double dist;

	scanf("%d", &test);

	while(test--){
		scanf("%d %lf", &n, &dist);
		vector<pii> coord;

        init();
		source = 2 * n + 1;
		totalPenguine = 0;

		for(int i = 0; i < n; i++){
			scanf("%d %d %d %d", &x, &y, &penguine, &cap);
			coord.pb(make_pair(x, y));
			if(penguine > 0){		//if the coordinate has a penguine connect with source
				graph[source].pb(i);
				graph[i].pb(source);
				capacity[source][i] = penguine;
				totalPenguine += penguine;
			}
			if(cap > 0){		//if the vertex has capacity
				graph[i].pb(i + n);
				graph[i+n].pb(i);
				capacity[i][i+n] += cap;
			}
		}

		for(int i = 0; i < n; i++){
			for(int j = i + 1; j < n; j++){
				double temp = calculateDistance(coord[i].first, coord[i].second, coord[j].first, coord[j].second);
				if(temp <= dist){
					graph[i+n].pb(j);
					graph[j].pb(i+n);
					graph[j+n].pb(i);
					graph[i].pb(j+n);
					capacity[i+n][j] = inf;
					capacity[j+n][i] = inf;
				}
			}
		}

		bool flag = false;
		for(int i = 0; i < n; i++){
			if(maxFlow(source, i) == totalPenguine){
				if(flag)	printf(" ");
				printf("%d", i);
				flag = true;
			}
		}

        if(flag)    printf("\n");
		else    	printf("-1\n");
	}

	return 0;
}
