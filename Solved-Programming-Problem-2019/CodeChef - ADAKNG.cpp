#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int dirx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int diry[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int r, c, k;
int visited[10][10], dist[10][10];

typedef pair<int, int> pii;

int bfs(int sx, int sy)
{
    memset(visited, 0, sizeof(visited));
    int cnt = 1;
    visited[sx][sy] = 1;
    dist[sx][sy] = 0;

    queue<pii>q;
    q.push(make_pair(sx, sy));

    while(!q.empty()){
        pii u = q.front();
        q.pop();

        for(int i = 0; i < 8; i++){
            int tx = u.first + dirx[i];
            int ty = u.second + diry[i];
            if(tx >= 1 && tx <= 8 && ty >= 1 && ty <= 8 && !visited[tx][ty]){
                dist[tx][ty] = dist[u.first][u.second] + 1;
                visited[tx][ty] = 1;
                if(dist[tx][ty] <= k){
                    cnt++;
                    q.push(make_pair(tx, ty));
                }
            }
        }
    }

    return cnt;
}
int main()
{
    int test;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d %d", &r, &c, &k);
        int result = bfs(r, c);
        printf("%d\n", result);
    }

    return 0;
}
