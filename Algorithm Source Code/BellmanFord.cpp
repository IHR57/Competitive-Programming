#include <bits/stdc++.h>
#define MAX 1005
#define mp make_pair
using namespace std;

struct edge{
    int a, b, cost;
    edge(int t1, int t2, int t3){
        a = t1, b = t2, cost = t3;
    }
};

vector<edge> e;
const int inf = 1<<28;
int n, m;

void bellmanFord(int src)           //call this if we don't have to print negative cycle
{
    vector<int> dist(n, inf);
    vector<int> p(n-1);
    dist[src] = 0;

    for(;;){
        bool isAnyUpdate = false;
        for(int j = 0; j < m; j++){
            if(dist[e[j].a] < inf){         //if the graph contains negative weight edges
                if(dist[e[j].a] + e[j].cost < dist[e[j].b]){
                    dist[e[j].b] = dist[e[j].a] + e[j].cost;
                    p[e[j].b] = e[j].a;         //for printing path
                    isAnyUpdate = true;
                }
            }
        }
        if(!isAnyUpdate)
            break;
    }
    for(int i = 0; i < n; i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;
}

void bellmanFordNC(int src)
{
    vector<int> dist(n, inf);
    vector<int> p(n-1);
    dist[src] = 0;
    int x;

    for(int i = 0; i < n; i ++){
        x = -1;
        for(int j = 0; j < m; j++){
            if(dist[e[j].a] < inf){         //if the graph contains negative weight edges
                if(dist[e[j].a] + e[j].cost < dist[e[j].b]){
                    dist[e[j].b] = max(-inf, dist[e[j].a] + e[j].cost);
                    p[e[j].b] = e[j].a;         //for printing path
                    x = e[j].b;
                }
            }
        }
    }
    if(x == -1){
        printf("No Negative Cycle Found.\n");
    }
    else{
        int y = x;
        for(int i = 0; i < n; i++)
            y = p[y];

        vector<int> path;
        for(int curr = y; ; curr = p[curr]){
            path.push_back(curr);
            if(curr == y && path.size() > 1){
                break;
            }
        }
        reverse(path.begin(), path.end());
        for(int i = 0; i < path.size(); i++){
            cout<<path[i]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int u, v, cost;

    scanf("%d %d",  &n, &m);
    for(int i = 0; i < m; i++){
        scanf("%d %d %d", &u, &v, &cost);
        u--, v--;
        e.push_back(edge(u, v, cost));
    }

    bellmanFord(0);

    return 0;
}
