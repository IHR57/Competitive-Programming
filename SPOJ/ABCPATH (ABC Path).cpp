#include <bits/stdc++.h>
#define MAX 55
using namespace std;

typedef pair<int, int> pii;

int grid[MAX][MAX], dist[MAX][MAX], visited[MAX][MAX];
int row, col;
int fx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int fy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main()
{
    char str[MAX];
    int caseNo = 1;

    while(scanf("%d %d", &row, &col) == 2){
        if(!row && !col)
            break;

        memset(dist, -1, sizeof(dist));
        memset(visited, 0, sizeof(visited));

        queue<pii> q;

        for(int i = 0; i < row; i++){
            scanf("%s", str);
            for(int j = 0; j < col; j++){
                grid[i][j] = str[j] - 'A';
                if(grid[i][j] == 0){
                    q.push(pii(i, j));
                    visited[i][j] = 1;
                    dist[i][j] = 0;
                }
            }
        }

        while(!q.empty()){
            pii u = q.front();
            q.pop();

            for(int k = 0; k < 8; k++){
                int tx = u.first + fx[k];
                int ty = u.second + fy[k];
                if(tx >= 0 && tx < row && ty >= 0 && ty < col && !visited[tx][ty]){
                    if(grid[tx][ty] == grid[u.first][u.second] + 1){
                        visited[tx][ty] = 1;
                        dist[tx][ty] = dist[u.first][u.second] + 1;
                        q.push(pii(tx, ty));
                    }
                }
            }
        }

        int Max = -1;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(dist[i][j] > Max)
                    Max = dist[i][j];
            }

        }

        printf("Case %d: %d\n", caseNo++, Max + 1);
    }

    return 0;
}
