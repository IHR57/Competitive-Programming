#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <sstream>
#define MAX 105
using namespace std;

typedef vector<int> vi;

vi adjList[MAX], dfs_num, dfs_low, articulation_vertex, dfs_parent;
int visited[MAX], dfsRoot, rootChildren, dfsNumberCounter;

void ArticulationPoint(int u)
{
    dfs_num[u] = dfs_low[u] = dfsNumberCounter++;
    visited[u] = 1;

    for(int j = 0; j < adjList[u].size(); j++){
        int v = adjList[u][j];
        if(!visited[v]){
            dfs_parent[v] = u;
            if(u == dfsRoot)    rootChildren++;
            ArticulationPoint(v);      //recursive call

            if(dfs_low[v] >= dfs_num[u])
                articulation_vertex[u] = 1;
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
        else if(v != dfs_parent[u]){    //if back edge and not direct cycle
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        }
    }
}

int main()
{
    int node, edgeNo, v;
    string str;

    while(1){
        scanf("%d\n", &node);
        if(node == 0)   break;

        dfs_num.assign(node, 0); dfs_low.assign(node, 0); articulation_vertex.assign(node, 0); dfs_parent.assign(node, 0);
        while(1){
            getline(cin, str);
            istringstream is(str);

            is>>edgeNo;

            if(edgeNo == 0)
                break;
            edgeNo--;
            while(is>>v){
                v--;
                adjList[edgeNo].push_back(v);
                adjList[v].push_back(edgeNo);
            }
        }
        memset(visited, 0, sizeof(visited));        //initialize all node are unvisited
        dfsNumberCounter = 0;

        for(int i = 0; i < node; i++){
            if(!visited[i]){
                dfsRoot = i;
                rootChildren = 0;
                ArticulationPoint(i);
                articulation_vertex[dfsRoot] = (rootChildren > 1);      //if root has more than one children
            }
        }

        int count = 0;
        for(int i = 0; i < node; i++){
            if(articulation_vertex[i])
                count++;
        }

        printf("%d\n", count);

        for(int i = 0; i <= node; i++){
            adjList[i].clear();
        }
    }

    return 0;
}
