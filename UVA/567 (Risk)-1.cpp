#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#define MAX 100
using namespace std;

vector<int> graph[MAX];
char color[MAX];
int dist[MAX];

const int INF = 1 << 28;

int breadthFirst(int source, int destination)
{
    for(int i = 0; i < MAX; i++){
        color[i] = 'w';
        dist[i] = INF;
    }

    queue<int> q;

    q.push(source);
    dist[source] = 0;
    color[source] = 'g';

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int i = 0; i < graph[u].size(); i++){
            if(color[graph[u][i]] == 'w'){
                dist[graph[u][i]] = dist[u] + 1;
                color[graph[u][i]] = 'g';
                q.push(graph[u][i]);
            }
        }

        color[u] = 'b';
    }

    return dist[destination];
}

int main()
{
    int a, b, test, num, cases = 1, n, i = 1;

    while(scanf("%d", &num) != EOF){
        for(int k = 0; k < num; k++){
            scanf("%d", &n);
            graph[i].push_back(n);
            graph[n].push_back(i);
        }

        if(i == 19)
        {
            scanf("%d", &test);
            printf("Test Set #%d\n", cases++);
            while(test--){
                scanf("%d %d", &a, &b);
                int result = breadthFirst(a, b);
                printf("%2d to %2d: %d\n", a, b, result);
            }
            printf("\n");
            i = 0;
            for(int i = 0; i < MAX; i++){
                graph[i].clear();
            }
        }

        i++;
    }

    return 0;
}
