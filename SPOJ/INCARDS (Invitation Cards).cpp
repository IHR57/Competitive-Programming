#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#define MAX 1000005
#define pb push_back
using namespace std;

typedef long long lint;
typedef pair<int, int> pii;

vector<int> graph[MAX], revGraph[MAX], cost[MAX], revCost[MAX];
int dist[MAX];
const int inf = 1<<28;

struct node
{
    int nodeNo, weight;
};

bool operator<(node A, node B)
{
    return A.weight > B.weight;
}

void dijkstra1(int source)
{
    for(int i = 0; i < MAX; i++)
        dist[i] = inf;

    node u, v;
    u.nodeNo = source, u.weight = 0;
    dist[source] = 0;
    priority_queue<node> pq;
    pq.push(u);

    while(!pq.empty()){
        u = pq.top();
        pq.pop();

        for(int i = 0; i < graph[u.nodeNo].size(); i++){
            v.nodeNo = graph[u.nodeNo][i];
            v.weight = cost[u.nodeNo][i] + dist[u.nodeNo];
            if(v.weight < dist[v.nodeNo]){      //update cost
                dist[v.nodeNo] = v.weight;
                pq.push(v);
            }
        }
    }
}

void dijkstra2(int source)
{
    for(int i = 0; i < MAX; i++)
        dist[i] = inf;

    node u, v;
    u.nodeNo = source, u.weight = 0;
    dist[source] = 0;
    priority_queue<node> pq;
    pq.push(u);

    while(!pq.empty()){
        u = pq.top();
        pq.pop();

        for(int i = 0; i < revGraph[u.nodeNo].size(); i++){
            v.nodeNo = revGraph[u.nodeNo][i];
            v.weight = revCost[u.nodeNo][i] + dist[u.nodeNo];
            if(v.weight < dist[v.nodeNo]){      //update cost
                dist[v.nodeNo] = v.weight;
                pq.push(v);
            }
        }
    }
}

int main()
{
    int test, p, q, u, v, w;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &p, &q); //node and edge
        while(q--){
            scanf("%d %d %d", &u, &v, &w);      //directed graph with cost
            graph[u].pb(v);
            revGraph[v].pb(u);
            cost[u].pb(w);
            revCost[v].pb(w);
        }

        lint sum = 0;
        dijkstra1(1);
        for(int i = 1; i <= p; i++){
            sum += dist[i];
        }
        //cout<<sum<<endl;
        dijkstra2(1);
        for(int i = 1; i <= p; i++){
            sum += dist[i];
        }

        printf("%lld\n", sum);

        for(int i = 0; i < MAX; i++){
            graph[i].clear();
            revGraph[i].clear();
            cost[i].clear();
            revCost[i].clear();
        }
    }

    return 0;
}
