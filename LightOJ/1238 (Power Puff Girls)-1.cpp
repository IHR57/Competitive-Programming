//Problem ID: LightOJ 1238 (Power Puff Girls)
//Programmer: IQBAL HOSSAIN     Description: BFS in 2D Grid
//Date: 11-08-17
#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <algorithm>
#include <string.h>
#define pb push_back
#define MAX 30
using namespace std;

int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};
int cell[MAX][MAX], row, col, dx, dy;
int dist[MAX][MAX], visited[MAX][MAX];
const int inf = 1<<28;

struct node
{
    int first, second;
};

void breadthFirst(int sx, int sy)
{
    memset(visited, 0, sizeof(visited));
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++)
            dist[i][j] = inf;
    }

    queue<node>q;
    node n;
    n.first = sx, n.second = sy;
    q.push(n);

    visited[sx][sy] = 1;
    dist[sx][sy] = 0;

    while(!q.empty()){
        node u = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){
            int tx = u.first + fx[i];
            int ty = u.second + fy[i];
            if(tx >= 0 && tx < row && ty >= 0 && ty < col && !visited[tx][ty] && cell[tx][ty] != -1){
                visited[tx][ty] = 1;
                dist[tx][ty] = dist[u.first][u.second] + 1;
                node temp;
                temp.first = tx, temp.second = ty;
                q.push(temp);
            }
        }
    }
}

int main()
{
    char str[100];
    int test, caseNo = 1;
    int s1x, s2x, s3x, s1y, s2y, s3y;
    int Blossom, Bubbles, Buttercup;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &row, &col);
        for(int i = 0; i < row; i++){
            cin>>str;
            for(int j = 0; j < col; j++){
                if(str[j] == '#' || str[j] == 'm')
                    cell[i][j] = -1;
                else
                    cell[i][j] = 1;
                if(str[j] == 'a')
                    s1x = i, s1y = j;
                else if(str[j] == 'b')
                    s2x = i, s2y = j;
                else if(str[j] == 'c')
                    s3x = i, s3y = j;
                else if(str[j] == 'h')
                    dx = i, dy = j;
            }
        }
        breadthFirst(dx, dy);

        printf("Case %d: %d\n", caseNo++, max(max(dist[s1x][s1y], dist[s2x][s2y]), dist[s3x][s3y]));
    }

    return 0;
}
