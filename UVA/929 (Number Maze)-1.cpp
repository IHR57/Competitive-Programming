#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#define MAX 1005
#define pb push_back
using namespace std;

typedef long long lint;
typedef pair<int, int> pii;

int fx[]  = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};
int visited[MAX][MAX], cost[MAX][MAX], dist[MAX][MAX];
int row, col;
const int inf = 1<<28;

struct node{
    int x, y, weight;
};

bool operator<(node A, node B)
{
    return A.weight > B.weight;
}

int dijkstra(int sx, int sy)
{
    memset(visited, 0, sizeof(visited));

    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++)
            dist[i][j] = inf;
    }

    priority_queue<node> pq;
    visited[sx][sy] = 1;
    dist[sx][sy] = 0;
    node u, v;
    u.x = sx, u.y = sy, u.weight = 0;
    pq.push(u);

    while(!pq.empty()){
        u = pq.top();
        pq.pop();

        for(int k = 0; k < 4; k++){
            int tx = u.x + fx[k];
            int ty = u.y + fy[k];
            int cst = u.weight;
            if(tx >= 0 && tx < row && ty >= 0 && ty < col && !visited[tx][ty]){
                v.x = tx, v.y = ty;
                v.weight = dist[u.x][u.y] + cost[tx][ty];
                if(dist[v.x][v.y] > v.weight){
                    dist[v.x][v.y] = v.weight;
                    pq.push(v);
                }
            }
        }
    }

    return dist[row-1][col-1] + cost[sx][sy];
}

int main()
{
    int test;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &row, &col);
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                scanf("%d", &cost[i][j]);
            }
        }

        int result = dijkstra(0, 0);
        printf("%d\n", result);
    }

    return 0;
}
