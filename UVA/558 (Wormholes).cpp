#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 1005
using namespace std;

struct data
{
    int u, v, w;
};

vector<data> graph;
int dist[MAX];
const int INF = 1<<28;
int n, m;

bool BellmanFord(int source)
{
    for(int i = 0; i < n; i++){
        dist[i] = INF;
    }

    dist[source] = 0;

    for(int j = 1; j < n; j++){
        for(int i = 0; i < m; i++){
            int u = graph[i].u;
            int v = graph[i].v;

            if(dist[u] + graph[i].w < dist[v]){     //relaxation
                dist[v] = dist[u] + graph[i].w;
            }
        }
    }

    bool negativeCycle = false;

    for(int i = 0; i < m; i++){
        int u = graph[i].u;
        int v = graph[i].v;

         if(dist[u] + graph[i].w < dist[v]){     //if there is possibility of update after n - 1 times
                dist[v] = dist[u] + graph[i].w;
                negativeCycle = true;
                return negativeCycle;
        }
    }

    return negativeCycle;
}

int main()
{
    int test, a, b, cost;

    cin>>test;

    while(test--){
        cin>>n>>m;
        for(int i = 0; i < m; i++){
            cin>>a>>b>>cost;
            data get;
            get.u = a, get.v = b, get.w = cost;
            graph.push_back(get);
        }

        bool result = BellmanFord(0);       //check if cycle exits

        cout<<(result ? "possible\n" : "not possible\n");

        graph.clear();
    }

    return 0;
}
