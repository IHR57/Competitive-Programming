#include <iostream>
#include <cstdio>
#include <vector>
#include <string.h>
#define MAX 30
using namespace std;

int graph[MAX][MAX], mx, node, edge;

void dfs(int source, int dep)
{
    if(dep > mx){
        mx = dep;
    }

    int i;

    for(i = 0; i < node; i++){
        if(graph[source][i]){
            graph[source][i] = 0;
            graph[i][source] = 0;       //make them visited
            dfs(i, dep+1);       //recursive call
            graph[source][i] = 1;
            graph[i][source] = 1;
        }
    }
}

int main()
{
    int a, b;

    while(scanf("%d %d", &node, &edge) == 2){
        if(!node && !edge)
            break;

        memset(graph, 0, sizeof(graph));        //initialize graph

        while(edge--){
            scanf("%d %d", &a, &b);
            graph[a][b] = 1;        //bidirectional
            graph[b][a] = 1;
        }
        mx = 0;
        for(int i = 0; i < node; i++){
            dfs(i, 0);
        }

        printf("%d\n", mx);
    }

    return 0;
}
