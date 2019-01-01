#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>
#include <queue>
#define MAX 105
using namespace std;

typedef vector<int> vi;
typedef long long lint;

vi graph[MAX], parent, discoveryTime, low, artiPoints;
bool visited[MAX];
int counter, dfsRoot, rootChildren;

void articulation(int u, int root)
{
    discoveryTime[u] = low[u] = counter++;
    visited[u] = true;

    int children = 0;

    for(int i = 0; i < graph[u].size(); i++){
        int v = graph[u][i];
        if(!visited[v]){
            parent[v] = u;
            children++;
            articulation(v, root);

            low[u] = min(low[u], low[v]);     //update row if there exists back edge

            if(u == root && children > 1){
                artiPoints[u] = 1;
            }
            else if(u != root && low[v] >= discoveryTime[u])
                artiPoints[u] = 1;
        }
        else if(v != parent[u]){
            low[u] = min(low[u], discoveryTime[v]);
        }
    }
}

int main()
{
    int nodeNo, edgeNo, caseNo = 1, line = 0;
    char first[50], second[50], str[MAX][50];

    while(scanf("%d", &nodeNo) == 1){
        if(!nodeNo) break;

        parent.assign(nodeNo, 0), discoveryTime.assign(nodeNo, 0);      //initializing
        low.assign(nodeNo, 0), artiPoints.assign(nodeNo, 0);

        map<string, int> myMap;
        map<int, string> Map2;
        int idx = 0;            //index for mapping

        for(int i = 0; i < nodeNo; i++){
            cin>>first;
            if(myMap.find(first) == myMap.end()){   //if it was not mapped before
                myMap[first] = idx;
                Map2[idx] = first;
                idx++;
            }
        }

        scanf("%d", &edgeNo);
        for(int i = 0; i < edgeNo; i++){
            cin>>first>>second;
            int u = myMap[first];
            int v = myMap[second];
            graph[u].push_back(v);      //connecting the node
            graph[v].push_back(u);
        }

        memset(visited, false, sizeof(visited));
        counter = 0;

        for(int i = 0; i < nodeNo; i++){
            if(!visited[i]){
                articulation(i, i);
            }
        }

        vector<string> vs;

        for(int i = 0; i < nodeNo; i++){
            if(artiPoints[i])
                vs.push_back(Map2[i]);
        }

        if(line)    printf("\n");
        line = 1;

        printf("City map #%d: %d camera(s) found\n", caseNo++, vs.size());

        sort(vs.begin(), vs.end());

        for(int i = 0; i < vs.size(); i++){
            cout<<vs[i]<<endl;
        }

        for(int i = 0; i < MAX; i++){
            graph[i].clear();
        }

        myMap.clear();
        Map2.clear();
    }

    return 0;
}
