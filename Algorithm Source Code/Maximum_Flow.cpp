#include <bits/stdc++.h>
#define MAX 1005
using namespace std;

vector<int> graph[MAX];
int cost[MAX][MAX], flow, parent[MAX];
const int inf = 1<<28;

bool augmentedPath(int source, int sink)
{
    memset(parent, -1, sizeof(parent));
    queue<int> q;
    q.push(source);

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int i = 0; i < graph[u].size(); i++){
            int v = graph[u][i];
            if(parent[v] == -1 && cost[u][v] > 0){
                parent[v] = u;
                q.push(v);
                if(v == sink)
                    return true;
            }
        }
    }

    return false;
}
void path(int v, int source)
{
    int u = parent[v];
    flow = min(flow, cost[u][v]);
    if(source != u)
        path(u, source);
    cost[u][v] -= flow;
    cost[v][u] += flow;
    return;
}

int maxFlow(int source, int sink)
{
    int ret = 0;
    while(augmentedPath(source, sink)){
        flow = inf;
        path(sink, source);
        ret += flow;
    }
    return ret;
}
int main()
{
    int node, source, sink, edges;
    scanf("%d %d %d %d", &node, &source, &sink, &edges);

    for(int i = 0; i < edges; i++){
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);
        graph[u].push_back(v);
        graph[v].push_back(u);
        cost[u][v] += c;
        cost[v][u] += c;
    }
    printf("%d\n", maxFlow(source, sink));

    return 0;
}
