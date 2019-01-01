#include <bits/stdc++.h>
#define MAX 205
using namespace std;

int visited[MAX][MAX], dist[MAX][MAX];

typedef pair<int, int> pii;

int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};

int main()
{
    int test, row, col;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &row, &col);
        memset(visited, 0, sizeof(visited));
        char str[MAX];
        queue<pii> q;
        for(int i = 0; i < row; i++){
            scanf("%s", str);
            for(int j = 0; j < col; j++){
                if(str[j] == '1'){
                    dist[i][j] = 0;
                    visited[i][j] = 1;
                    q.push(make_pair(i, j));
                }
            }
        }

        while(!q.empty()){
            pii u = q.front();
            q.pop();

            for(int k = 0; k < 4; k++){
                int tx = u.first + fx[k];
                int ty = u.second + fy[k];

                if(tx >= 0 && tx < row && ty >= 0 && ty < col && !visited[tx][ty]){
                    visited[tx][ty] = 1;
                    dist[tx][ty] = dist[u.first][u.second] + 1;
                    q.push(make_pair(tx, ty));
                }
            }
        }

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                printf("%d ", dist[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}
