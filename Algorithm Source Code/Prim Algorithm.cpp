#include <iostream>
#include <cstdio>
#include <limits.h>
#define V 5     //number of vertex

int minKey(int key[], bool mstSet[])        //this function return minimum index that are not included
{
    int Min = INT_MAX, index;

    for(int i = 0; i < V; i++){
        if(mstSet[i] == false && key[i] < Min){
            Min = key[i];
            index = i;
        }
    }

    return index;
}

int printMST(int parent[], int n, int graph[V][V])
{
    for(int i = 1; i < V; i++){
        printf("%d  -  %d    %d\n", parent[i], i, graph[i][parent[i]]);
    }
}

void prim(int graph[V][V])
{
    int parent[V];
    int key[V];
    bool mstSet[V];

    for(int i = 0; i < V; i++){
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for(int i = 0; i < V - 1; i++){
        int u = minKey(key, mstSet);

        mstSet[u] = true;

        for(int v = 0; v < V; v++){
            if(graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]){
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    printMST(parent, V, graph);
}

int main()
{
    int graph[V][V] = {{0, 2, 0, 6, 0},
                       {2, 0, 3, 8, 5},
                       {0, 3, 0, 0, 7},
                       {6, 8, 0, 0, 9},
                       {0, 5, 7, 9, 0}};
    prim(graph);

    return 0;
}
