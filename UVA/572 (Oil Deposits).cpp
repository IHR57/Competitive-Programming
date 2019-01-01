#include <bits/stdc++.h>
#define MAX 105
using namespace std;

int cell[MAX][MAX], visited[MAX][MAX];
int dx[] = {0, 0, -1, 1, -1, 1, -1, 1};
int dy[] = {-1, 1, 0, 0, -1, 1, 1, -1};
int row, col;

typedef pair<int, int> p;

void bfs(int sx, int sy)
{
    visited[sx][sy] = 1;

    queue<p> q;
    q.push(p(sx, sy));

    while(!q.empty()){
        p top = q.front();
        q.pop();

        for(int k = 0; k < 8; k++){     //checking all the possible move
            int tx = top.first + dx[k];
            int ty = top.second + dy[k];

            //check valid position
            if(tx >= 0 && tx < row && ty >= 0 && ty < col && visited[tx][ty] == 0 && cell[tx][ty] == 1){
                visited[tx][ty] = 1;
                q.push(p(tx, ty));
            }
        }
    }
}

int main()
{
    while(scanf("%d %d", &row, &col) == 2){
        if(row == 0)
            break;
        char str[110];

        for(int i = 0; i < row; i++){
            scanf("%s", str);
            for(int j = 0; j < col; j++){
                (str[j] == '@') ? cell[i][j] = 1 : cell[i][j] = 0;
            }
        }

        memset(visited, 0, sizeof(visited));        //initialize

        int count = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(cell[i][j] == 1 && !visited[i][j]){
                    bfs(i, j);
                    count++;
                }
            }
        }

        printf("%d\n", count);
    }

    return 0;
}
