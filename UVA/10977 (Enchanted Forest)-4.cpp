#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#define MAX 205
#define pb push_back
using namespace std;

typedef long long lint;
typedef pair<int, int> pii;

int row, col;
int cell[MAX][MAX], dist[MAX][MAX], visited[MAX][MAX];
int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};
const int inf = 1<<28;

bool breadthFirst(int sx, int sy)
{
    if(cell[sx][sy] == -1)
        return false;

    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++)
            dist[i][j] = inf;
    }

    visited[sx][sy] = 1;
    dist[sx][sy] = 0;
    queue<pii> q;
    q.push(pii(sx, sy));

    while(!q.empty()){
        pii u = q.front();
        q.pop();

        for(int k = 0; k < 4; k++){
            int tx = u.first + fx[k];
            int ty = u.second + fy[k];

            if(tx >= 1 && tx <= row && ty >= 1 && ty <= col && !visited[tx][ty] && cell[tx][ty] != -1){
                visited[tx][ty] = 1;
                dist[tx][ty] = dist[u.first][u.second] + 1;
                q.push(pii(tx, ty));
            }
        }
    }

    if(dist[row][col] == inf)
        return false;
    return true;
}

int main()
{
    int blockCell, u, v, jigglypuffs, sx, sy, loudness;

    while(scanf("%d %d", &row, &col) == 2){
        if(row == 0 && col == 0)
            break;
        scanf("%d", &blockCell);        //number of blocked cell

        for(int i = 0; i < MAX; i++){
            for(int j = 0; j < MAX; j++){
                cell[i][j] = 0;
                visited[i][j] = 0;
            }
        }

        while(blockCell--){
            scanf("%d %d", &u, &v);
            cell[u][v] = -1;
            visited[u][v] = 1;
        }

        scanf("%d", &jigglypuffs);

        while(jigglypuffs--){
            scanf("%d %d %d", &sx, &sy, &loudness);
            queue<pii> q;
            q.push(pii(sx, sy));
            visited[sx][sy] = 1;
            cell[sx][sy] = -1;

            while(!q.empty()){
                pii u = q.front();
                q.pop();

                for(int k = 0; k < 4; k++){
                    int tx = u.first + fx[k];
                    int ty = u.second + fy[k];
                    if(tx >= 1 && tx <= row && ty >= 1 && ty <= col && !visited[tx][ty] && cell[tx][ty] != -1){
                        if(((sx - tx) * (sx - tx) + (sy - ty) * (sy - ty)) <= (loudness * loudness)){
                            visited[tx][ty] = 1;
                            cell[tx][ty] = -1;
                            q.push(pii(tx, ty));
                        }
                    }
                }
            }
        }

        bool result = breadthFirst(1, 1);
        if(result)
            printf("%d\n", dist[row][col]);
        else
            printf("Impossible.\n");
    }

    return 0;
}
