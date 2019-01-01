//Problem ID: LightOJ 1175 (Jane and the Frost Giants)
//Programmer: IQBAL HOSSAIN     Description: BFS/DFS
//Date: 16-08-17
#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <queue>
#include <vector>
#define pb push_back
#define MAX 1005
using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
const int inf = 1<<28;

typedef pair<int, int> pii;
int visited[MAX][MAX], cell[MAX][MAX], dist[MAX][MAX];
string str[MAX], temp;

int main()
{
    int test, caseNo = 1, row, col;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &row, &col);
        for(int i = 0; i < row; i++){
            cin>>temp;
            str[i] = temp;
        }

        queue<pii> q;
        int sx, sy;

        memset(visited, 0, sizeof(visited));

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(str[i][j] == '#'){
                    cell[i][j] = -1;
                    dist[i][j] = inf;
                }
                else if(str[i][j] == 'F'){
                    cell[i][j] = 1;
                    visited[i][j] = 1;
                    dist[i][j] = inf;
                    q.push(pii(i, j));
                }
                else if(str[i][j] == 'J'){
                    sx = i, sy = j;
                    visited[i][j] = 1;
                    cell[i][j] = 1;
                    dist[i][j] = 0;
                }
                else{
                    cell[i][j] = 0;
                    dist[i][j] = inf;
                }
            }
        }
        q.push(pii(sx, sy));

        while(!q.empty()){
            pii u = q.front();
            q.pop();

            for(int k = 0; k < 4; k++){
                int tx = u.first + dx[k];
                int ty = u.second + dy[k];

                if(tx >= 0 && tx < row && ty >= 0 && ty < col && !visited[tx][ty] && cell[tx][ty] != -1){
                    if(cell[tx][ty] == 0){
                        visited[tx][ty] = 1;
                        if(dist[u.first][u.second] != inf){
                            dist[tx][ty] = dist[u.first][u.second] + 1;
                            cell[u.first][u.second] = 0;
                        }
                        q.push(pii(tx, ty));
                    }
                }
            }
        }

        int Min = inf;
        int flag = 0;

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(i == 0 || i == row - 1 || j == 0 || j == col - 1){
                    if(dist[i][j] < Min){
                        Min = dist[i][j];
                        flag = 1;
                    }
                }
               // cout<<dist[i][j]<<" ";
            }
            //cout<<endl;
        }

        if(!flag)
            printf("IMPOSSIBLE\n");
        else
            printf("%d\n" , Min + 1);
    }

    return  0;
}

