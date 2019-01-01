#include <bits/stdc++.h>
#define MAX 105
using namespace std;

int res[MAX][MAX], s, t, maxFlow, pathFlow;
vector<int> adjList[MAX];
vector<int> parent;
const int INF = 1<<28;

void augment(int v, int minEdge)
{
    if(v == s){     //base case;
        pathFlow = minEdge;
        return;
    }
    else if(parent[v] != -1){
        augment(parent[v], min(minEdge, res[parent[v]][v]));
        res[parent[v]][v] -= pathFlow;
        res[v][parent[v]] += pathFlow;      //increase the flow of opposite direction
    }
}

void EdmondsKarp()
{
    maxFlow = 0;

    while(1){
        pathFlow = 0;
        bitset<MAX> vis;
        vis[s] = true;

        queue<int> q;
        q.push(s);
        parent.assign(MAX, -1);

        while(!q.empty()){
            int u = q.front();
            q.pop();

            if(u == t)
                break;          //if we reach destination

            for(int j = 0; j < adjList[u].size(); j++){
                int v = adjList[u][j];
                if(res[u][v] > 0 && !vis[v]){
                    vis[v] = true;
                    q.push(v);
                    parent[v] = u;
                }
            }
        }

        augment(t, INF);            //find augmented path
        if(pathFlow == 0)       //if residual capacity is zero
            break;
        maxFlow += pathFlow;
    }
}

int main()
{
    int node, edges, u, v, capacity, test = 1;

    while(scanf("%d", &node) == 1){
        if(!node)
            break;
        scanf("%d %d %d", &s, &t, &edges);
        s--, t--;

        for(int i = 0; i < node; i++)           //initialize
            for(int j = 0; j < node; j++)
                res[i][j] = 0;

        while(edges--){
            scanf("%d %d %d", &u, &v, &capacity);
            adjList[u-1].push_back(v-1);
            adjList[v-1].push_back(u-1);
            res[u-1][v-1] += capacity;
            res[v-1][u-1] += capacity;
        }

        EdmondsKarp();

        printf("Network %d\n", test++);
        printf("The bandwidth is %d.\n\n", maxFlow);

        for(int i = 0; i < node; i++){
            adjList[i].clear();
        }
        parent.clear();
    }

    return 0;
}
