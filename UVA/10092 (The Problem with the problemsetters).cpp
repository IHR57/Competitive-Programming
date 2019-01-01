#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#define MAX 1050
using namespace std;

vector<int> graph[MAX];
int cap[MAX][MAX], parent[MAX], flow;
const int inf = 10000;

void init()
{
	memset(cap, 0, sizeof(cap));

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
			if(parent[v] == -1 && cap[u][v] > 0){
				parent[v]  = u;
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
	flow = min(flow, cap[u][v]);

	if(u != source)
		path(u, source);

	cap[u][v] -= flow;
	cap[v][u] += flow;

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
	int category, totalProblems, number, x, sum, problems[MAX];

	while(scanf("%d %d", &category, &totalProblems) == 2){
		if(!category && !totalProblems)
			break;
		init();			//initialize graph
		sum = 0;
		for(int i = 1; i <= category; i++){
            scanf("%d", &problems[i]);
            sum += problems[i];
			graph[0].push_back(i);
			graph[i].push_back(0);
			cap[0][i] = problems[i];
		}

		for(int i = 1; i <= totalProblems; i++){
			scanf("%d", &number);
			while(number--){
				scanf("%d", &x);
				graph[x].push_back(i+20);
				graph[i+20].push_back(x);
				cap[x][i+20] = inf;
			}
		}

		for(int i = 21; i <= 1020; i++){		//linking with sink
			graph[i].push_back(1021);		//we will consider 1021 as sink node
			graph[1021].push_back(i);
			cap[i][1021] = 1;
		}

		int ans = maxFlow(0, 1021);

        if(ans == sum){
            printf("1\n");
            for(int i = 1; i <= category; i++){
                int count = 0;
                for(int j = 1; j <= totalProblems; j++){
                    if(cap[j+20][i] > 0){
                        count++;
                        (count < problems[i]) ? printf("%d ", j) : printf("%d", j);
                    }

                }
                printf("\n");
            }
        }
        else{
            printf("0\n");
        }
	}

	return 0;
}
