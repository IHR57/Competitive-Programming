#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#include <map>
#define MAX 105
using namespace std;

vector<int> graph[MAX];
int dist[MAX], weight[MAX][MAX];
const int INF = 1<<28;

struct data
{
    int cellNo, cost;
};

bool operator<(data A, data B)
{
    return A.cost > B.cost;
}

void dijkstra(int source)
{
    for(int i = 0; i < MAX; i++)
        dist[i] = INF;

    priority_queue<data> pq;

    data u, v;

    u.cellNo = source; u.cost = 0;
    pq.push(u);
    dist[source] = 0;

    while(!pq.empty()){
        u = pq.top();
        int ucost = dist[u.cellNo];
        //int ii = u.cellNo;
        pq.pop();

        for(int i = 0; i < graph[u.cellNo].size(); i++){
            v.cellNo = graph[u.cellNo][i];
            v.cost = weight[u.cellNo][v.cellNo] + ucost;

            if(dist[v.cellNo] > v.cost){
                dist[v.cellNo] = v.cost;
                pq.push(v);
            }
        }
    }
}

int main()
{
    int test, count, totalCell , exitCell, Time, u, v, cost, edge;

    scanf("%d", &test);

    while(test--){
        count = 0;
        scanf("%d %d %d", &totalCell, &exitCell, &Time);
        exitCell--;
        scanf("%d", &edge);

        while(edge--){
            scanf("%d %d %d", &u, &v, &cost);
            u--; v--;
            graph[u].push_back(v);
            weight[u][v] = cost;
        }

        dijkstra(exitCell);

        for(int i = 0; i < totalCell; i++){
            //printf("distance from %d : %d\n", i+1, dist[i]);
            if(dist[i] <= Time || i == exitCell)
                count++;
        }

        printf("%d\n", count);
        if(test)
            printf("\n");

        for(int i = 0; i <= totalCell; i++){
            graph[i].clear();
        }
        memset(weight, 0, sizeof(weight));
    }

    return 0;
}
