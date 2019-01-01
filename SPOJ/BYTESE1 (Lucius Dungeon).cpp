#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
#define pb push_back
#define MAX 10010
using namespace std;

typedef long long lint;
vector<int> graph[MAX], cost[MAX];
int dist[MAX], cst[110][110];
const int inf = 1<<28;

int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};

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
    for(int i = 0; i < MAX; i++)
        dist[i] = inf;

    priority_queue<data> pq;
    data u, v;
    u.node = source, u.weight = 0;
    pq.push(u);
    dist[source] = 0;

    while(!pq.empty()){
        u = pq.top();
        pq.pop();

        for(int i = 0; i < graph[u.node].size(); i++){
            v.node = graph[u.node][i];
            v.weight = cost[u.node][i] + dist[u.node];

            if(v.weight < dist[v.node]){
                dist[v.node] = v.weight;
                pq.push(v);
            }
        }
    }
}

int main()
{
    int test, u, v, w, dx, dy, value;
    int row, col, bombsTime;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &row, &col);
        for(int i = 1; i <= row; i++){
            for(int j = 1; j <= col; j++){
                scanf("%d", &value);
                cst[i][j] = value;
                int u = (col * (i - 1)) + j;
                for(int k = 0; k < 4; k++){
                    int tx = i + fx[k];
                    int ty = j + fy[k];
                    if(tx >= 1 && tx <= row && ty >= 1 && ty <= col){
                        v = (col * (tx - 1)) + ty;
                        //cout<<u<<" "<<v<<endl;
                        graph[u].pb(v);
                        cost[u].pb(value);
                    }
                }
            }
        }

        scanf("%d %d %d", &dx, &dy, &bombsTime);
        int temp = (col * (dx - 1)) + dy;
        //cout<<temp<<endl;
        dijkstra(1);
        int result = bombsTime - (dist[temp] + cst[dx][dy]);

        if(result >= 0){
            printf("YES\n");
            printf("%d\n", result);
        }
        else
            printf("NO\n");

        for(int i = 0; i < MAX; i++){
            graph[i].clear();
            cost[i].clear();
        }
    }
}
