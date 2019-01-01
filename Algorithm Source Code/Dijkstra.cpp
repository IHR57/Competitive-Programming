#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

const int INF = 1 << 28;

struct Node
{
    int at, cost;

    Node(int _at, int _cost)        //Constructor
    {
        at = _at;
        cost = _cost;
    }
};

bool operator<(Node A, Node B)
{
    //Priority queue returns the greatest value so we need to write the comparator in a way
    //so that cheapest value becomes greatest value.

    return A.cost > B.cost;
}

struct Edge
{
    int v, w;
};

vector<Edge> adj[100];      //adjacency list for weighted edges
priority_queue<Node> pq;

int dist[100];
int n;

void dijkstra(int source)
{
    for(int i = 1; i <= n; i++){
        dist[i] = INF;
    }

    dist[source] = 0;

    pq.push(Node(s, 0));

    while(!pq.empty()){
        Node u = pq.top();
        pq.pop();

        if(u.cost != dist[u.at]){
            continue;
        }
        for(Edge e : adj[u.at]){
            if(dist[e.v] > u.cost + e.w){
                dist[e.v] = u.cost + e.w;
                pq.push(Node(e.v, dist[e.v]));
            }
        }
    }
}
