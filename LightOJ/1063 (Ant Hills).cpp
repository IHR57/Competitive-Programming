#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <vector>
#define MAX 10005
using namespace std;

vector<int> adjList[MAX], dfs_num, dfs_low, artVertex, parent;
int visited[MAX], dfsRoot, rootChild, counter;

void articulationPoints(int u)
{
    dfs_num[u] = dfs_low[u] = counter++;
    visited[u] = 1;

    for(int j = 0; j < adjList[u].size(); j++){
        int v = adjList[u][j];
        if(!visited[v]){
            parent[v] = u;
            if(u == dfsRoot){       //special case for root node
                rootChild++;
            }

            articulationPoints(v);      //recursive call;

            if(dfs_low[v] >= dfs_num[u]){       //condition for articulation vertex
                artVertex[u] = 1;
            }

            dfs_low[u] = min(dfs_low[u], dfs_low[v]);       //update dfs_low
        }

        else if(v != parent[u])     //if there exits back edge but not direct cycle
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
}

int main()
{
    int test, node, edge, cases = 1, u, v;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &node, &edge);

        dfs_num.assign(node, 0), dfs_low.assign(node, 0), artVertex.assign(node, 0), parent.assign(node, 0);    //initiaize

        while(edge--){
            scanf("%d %d", &u, &v);
            u--, v--;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        memset(visited, 0, sizeof(visited));
        counter = 0;

        for(int i = 0; i < node; i++){
            if(!visited[i]){
                dfsRoot = i;
                rootChild = 0;
                articulationPoints(i);
                artVertex[dfsRoot] = (rootChild > 1);       //if root has more than one child then it is articulation vertex
            }
        }

        int count = 0;

        for(int i = 0; i < node; i++){
            if(artVertex[i])
                count++;
        }

        printf("Case %d: %d\n", cases++, count);

        for(int i = 0; i <= node; i++)
            adjList[i].clear();
    }

    return 0;
}
