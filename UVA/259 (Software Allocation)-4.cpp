#include <bits/stdc++.h>
#define MAX 50
using namespace std;

vector<int> graph[MAX];
int parent[MAX], capacity[MAX][MAX], flow, save[MAX];
const int inf = 1000;

void init()
{
    memset(capacity, 0, sizeof(capacity));
    memset(save, 0, sizeof(save));

    for(int i = 0; i < MAX; i++)
        graph[i].clear();
}

bool augmentedPath(int source, int sink)		//this function return true if it is possible to find a valid path from source to sink
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

	capacity[u][v] -= flow;
	capacity[v][u] += flow;
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

	char input[200], input2[200], alphabet, task;
	int counter;

	for(; ;){
        if(gets(input) == 0) break;
        init();
        counter = 0;

        do{
            if(strcmp(input, "") == 0) break;
            sscanf(input, "%c%c %s", &alphabet, &task, input2);
            int idx = alphabet - 'A' + 1;

            graph[0].push_back(idx);				//we consider 0 as a source node
            graph[idx].push_back(0);
            capacity[0][idx] = task - 48;
            counter += task - 48;

            int len = strlen(input2);
            for(int i = 0; ; i++){
                if(input2[i] == ';')
                    break;

                int v = (input2[i] - 48) + 27;
                graph[idx].push_back(v);
                graph[v].push_back(idx);
                capacity[idx][v] = inf;
            }
        }
        while(gets(input));

        for(int i = 27; i < 37; i++){
            //connect each computer with sink
            graph[i].push_back(37);
            graph[37].push_back(i);
            capacity[i][37] = 1;
        }

        int ans = maxFlow(0, 37);

        if(ans == counter){
            for(int i = 27; i < 37; i++){
                int flag = 0;
                for(int j = 1; j <= 26; j++){
                    if(capacity[i][j]){
                        printf("%c", j + 'A' - 1);
                        flag = 1;
                        break;
                    }
                }
                if(!flag)   printf("_");
            }
            printf("\n");
        }
        else
            printf("!\n");
	}

	return 0;
}
