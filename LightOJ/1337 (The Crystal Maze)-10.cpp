#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
#define pb push_back
#define MAX 505
using namespace std;

typedef long long lint;
typedef pair<int, int> pii;

int cell[MAX][MAX], visited[MAX][MAX], row, col, cost[MAX][MAX];
int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};

int breadthFirst(int sx, int sy, int idx)
{
    int Count = 0;

    queue<pii> q;
    q.push(pii(sx, sy));
    visited[sx][sy] += idx;

    while(!q.empty()){
        pii u = q.front();
        q.pop();

        for(int k = 0; k < 4; k++){
            int tx = u.first + fx[k];
            int ty = u.second + fy[k];

            if(tx >= 0 && tx < row && ty >= 0 && ty < col && !visited[tx][ty] && cell[tx][ty] != -1){
                visited[tx][ty] += idx;
                if(cell[tx][ty] == 1)
                    Count++;
                q.push(pii(tx, ty));
            }
        }
    }

    return Count;
}

int main()
{
    int test, caseNo = 1, query, sx, sy;
    char str[600];

    scanf("%d", &test);

    while(test--){
        scanf("%d %d %d", &row, &col, &query);

        for(int i = 0; i < MAX; i++){
            for(int j = 0; j < MAX; j++){
                cell[i][j] = 0;
                cost[i][j] = 0;
                visited[i][j] = 0;
            }
        }

        for(int i = 0; i < row; i++){
            scanf("%s", str);
            for(int j = 0; j < col; j++){
                if(str[j] == '#')
                    cell[i][j] = -1;
                else if(str[j] == 'C')
                    cell[i][j] = 1;
                else
                    cell[i][j] = 0;
            }
        }

        //memset(visited, 0, sizeof(visited));

        int idx = 1, k = 0, ans[MAX*MAX];
        for(int i = 0; i < row; i++){       //pre calculate all cost
            for(int j = 0; j < col; j++){
                if(!visited[i][j] && cell[i][j] == 0){
                    ans[k] = breadthFirst(i, j, idx);
                    k++;
                    idx++;
                }
                cost[i][j] = ans[visited[i][j] - 1];
            }
        }

        printf("Case %d:\n", caseNo++);

        for(int i = 0; i < query; i++){
            scanf("%d %d", &sx, &sy);
            sx--, sy--;
            printf("%d\n", cost[sx][sy]);
        }
    }

    return 0;
}
