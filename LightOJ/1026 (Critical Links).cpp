#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <queue>
#include <vector>
#define MAX 10002
using namespace std;

vector< pair<int, int> > vp;

vector<int> adjList[MAX], dfs_num, dfs_low, dfs_parent, articulation_vertex;
int visited[MAX], dfsNumberCounter, dfsRoot, rootChildren;

void bridges(int u)
{
    dfs_num[u] = dfs_low[u] = dfsNumberCounter++;
    visited[u] = 1;

    for(int j = 0; j < adjList[u].size(); j++){
        int v = adjList[u][j];
        if(visited[v] == 0){
            dfs_parent[v] = u;

            bridges(v);      //recursive call
            if(dfs_low[v] > dfs_num[u]){            //if we find the bridge
                if(u < v)
                    vp.push_back(make_pair(u, v));
                else
                    vp.push_back(make_pair(v, u));
            }

            dfs_low[u] = min(dfs_low[u], dfs_low[v]);       //update dfs_low of u vertex
        }

        else if(v != dfs_parent[u])         //back edge and direct cycle
        {
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        }
    }
}

int main()
{
    int totalServer, serverNo, u, connectionNumber, cases = 1, test;

    scanf("%d", &test);

    while(test--){
        scanf("%d", &totalServer);
        dfs_num.assign(totalServer, 0), dfs_low.assign(totalServer, 0); //initialize
        articulation_vertex.assign(totalServer, 0), dfs_parent.assign(totalServer, 0);

        for(int j = 0; j < totalServer; j++){
            scanf("%d (%d)", &serverNo, &connectionNumber);

            while(connectionNumber--){
                scanf("%d", &u);
                adjList[serverNo].push_back(u);
            }
        }

        memset(visited, 0, sizeof(visited));
        dfsNumberCounter = 0;

        for(int i = 0; i < totalServer; i++){
            if(visited[i] == 0){
                bridges(i);
            }
        }

        sort(vp.begin(), vp.end());

        printf("Case %d:\n", cases++);
        printf("%d critical links\n", vp.size());

        for(int i = 0; i < vp.size(); i++){
            printf("%d - %d\n", vp[i].first, vp[i].second);
        }
        //printf("\n");
        for(int i = 0; i < totalServer; i++){
            adjList[i].clear();
        }
        vp.clear();
    }

    return 0;
}

