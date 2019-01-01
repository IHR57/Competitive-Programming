#include <bits/stdc++.h>
using namespace std;
#define MAX 5005

struct edge{
    int to, weight;
    edge(){}
    edge(int t, int w) : to(t), weight(w){}
    bool operator <(const edge &o) const{
        return o.weight < weight;
    }
};

vector<edge> graph[MAX];
int dist[2][MAX];

const int inf = 1<<28;

struct node{
    int op, v, w;
    node(){}
    node(int a, int b, int c) : op(a), v(b), w(c) {}
    bool operator < (const node &o) const{
        if(op == o.op)
            if(w == o.w)
                return v > o.v;
            return w > o.w;
        return op > o.op;
    }
};

int dijkstra(int s, int n)
{
    for(int i = 0; i < n; i++){
        dist[0][i] = dist[1][i] = inf;
    }

    dist[0][s] = 0;
    priority_queue<node> q;
    q.push(node(0, s, 0));

    while(!q.empty()){
        int nd = q.top().v;
        int cost = q.top().w;
        int op = q.top().op;
        q.pop();

        if(nd == n-1 && op == 1)
            return dist[1][nd];
        if(cost > dist[op][nd])
            continue;

        for(int i = 0; i < graph[nd].size(); i++){
            int to = graph[nd][i].to;
            int w_extra = graph[nd][i].weight;

            if(cost + w_extra < dist[0][to]){
                dist[1][to] = dist[0][to];
                dist[0][to] = cost + w_extra;
                q.push(node(1, to, dist[1][to]));
                q.push(node(0, to, dist[0][to]));
            }
            else if(cost + w_extra > dist[0][to] && cost + w_extra < dist[1][to]){
                dist[1][to] = cost + w_extra;
                q.push(node(1, to, dist[1][to]));
            }
        }
    }

    return inf;
}

int main()
{
    int test, caseNo = 1;

    scanf("%d", &test);

    while(test--){
        int n, r;
        scanf("%d %d", &n, &r);
        int u, v, w;

        for(int i = 0; i < n; i++)  graph[i].clear();
        for(int i = 0; i < r; i++){
            scanf("%d %d %d", &u, &v, &w);
            u--, v--;
            graph[u].push_back(edge(v, w));
            graph[v].push_back(edge(u, w));
        }

        dijkstra(0, n);

        printf("Case %d: %d\n", caseNo++, dist[1][n-1]);
    }

    return 0;
}
