#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#define MAX 505
using namespace std;

vector<int> graph[MAX], weight[MAX];
const int INF = 1 << 28;
int dist[MAX];

struct data
{
    int nodeNo, cost;
};

bool operator<(data A, data B)
{
    return A.cost > B.cost;
}

int dijkstra(int source)           //modified bfs
{
    //int dist[MAX];

    for(int i = 0; i < MAX; i++)
        dist[i] = INF;

    priority_queue<data> pq;

    data u, v;

    u.nodeNo = source; u.cost = 0;
    pq.push(u);
    dist[source] = 0;

    while(!pq.empty())
    {
        u = pq.top();
        pq.pop();
        int ucost = dist[u.nodeNo];

        for(int i = 0; i < graph[u.nodeNo].size(); i++){
            v.nodeNo = graph[u.nodeNo][i];
            v.cost = max(weight[u.nodeNo][i], ucost);

            if(v.cost < dist[v.nodeNo]){
                dist[v.nodeNo] = v.cost;
                pq.push(v);
            }
        }
    }

}

int main()
{
    int test, cases = 1, node, edge, a, b, cst, destination;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &node, &edge);

        while(edge--){
            scanf("%d %d %d", &a, &b, &cst);
            graph[a].push_back(b);
            graph[b].push_back(a);
            weight[a].push_back(cst);
            weight[b].push_back(cst);
        }

        scanf("%d", &destination);

        dijkstra(destination);

        printf("Case %d:\n", cases++);
        for(int i = 0; i < node; i++){
            (dist[i] == INF) ? printf("Impossible\n") : printf("%d\n", dist[i]);
        }

        for(int i = 0; i < node; i++){
            graph[i].clear();
            weight[i].clear();
        }
    }

    return 0;
}
