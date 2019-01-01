#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
#define pb push_back
#define MAX 3000
using namespace std;

typedef long long lint;
vector<int> graph[MAX], cost[MAX];
int dist[MAX], srcCount;
const int inf = 1<<28;

struct data
{
    int node, weight;
};

bool operator<(data A, data B)
{
    return A.weight > B.weight;
}

void dijkstra(int source)
{
    for(int i = 0; i < MAX; i++){
        dist[i] = inf;
    }

    priority_queue<data> pq;
    priority_queue<int> intq;
    data u, v;
    dist[source] = 0;
    u.node = source, u.weight = 0;
    pq.push(u);

    while(!pq.empty()){
        u = pq.top();
        pq.pop();

        for(int i = 0; i < graph[u.node].size(); i++){
            v.node = graph[u.node][i];
            v.weight = dist[u.node] + cost[u.node][i];

            if(v.weight < dist[v.node]){
                dist[v.node] = v.weight;
                pq.push(v);
                intq.push(dist[v.node]);
            }
        }
    }
}

int main()
{
    int test, caseNo = 1, u, v, w, nodeNo;

    scanf("%d", &test);

    while(test--){
        scanf("%d", &nodeNo);
        srcCount = 0;
        for(int i = 0; i < nodeNo - 1; i++){
            scanf("%d %d %d", &u, &v, &w);
            graph[u].push_back(v);
            graph[v].push_back(u);
            cost[u].push_back(w);
            cost[v].push_back(w);

            if(u == 0 || v == 0)
                srcCount++;
        }

        dijkstra(0);

       // printf("Case %d: %d\n", caseNo++, result);

        int Max = -1, src;
        for(int i = 0; i < nodeNo; i++){
            if(dist[i] > Max){
                Max = dist[i];
                src = i;
            }
        }

        Max = -1;
        dijkstra(src);

        for(int i = 0 ; i < nodeNo; i++){
            if(dist[i] > Max)
                Max = dist[i];
        }

        printf("Case %d: %d\n", caseNo++, Max);

        for(int i = 0; i < MAX; i++){
            graph[i].clear(); cost[i].clear();
        }
    }

    return 0;
}
