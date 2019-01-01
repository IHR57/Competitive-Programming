#include <bits/stdc++.h>
#define MAX 1005
using namespace std;

int dist[MAX][MAX], grid[MAX][MAX], row, col;
int fx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int fy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

struct data
{
    int x, y;
};

bool check(data temp)
{
    if(temp.x >= 0 && temp.x < row && temp.y >= 0 && temp.y < col && grid[temp.x][temp.y] != -1){
        return true;
    }
    return false;
}
int main()
{
    int test;
    char str[MAX];

    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &row, &col);
        memset(grid, 0, sizeof(grid));
        data source, destination;
        for(int i = 0; i < row; i++){
            scanf("%s", str);
            for(int j = 0; j < col; j++){
                dist[i][j] = 0;
                if(str[j] == 'S'){
                    dist[i][j] = 1;
                    source.x = i;
                    source.y = j;
                }
                else if(str[j] == 'F'){
                    destination.x = i;
                    destination.y = j;
                }
                else if(str[j] == 'X'){
                    grid[i][j] = -1;
                }
            }
        }

        queue<data> q;
        q.push(source);

        while(!q.empty()){
            data u = q.front();
            q.pop();

            for(int i = 0; i < 8; i++){
                data temp = u;
                temp.x += fx[i];
                temp.y += fy[i];
                while(check(temp)){
                    if(dist[temp.x][temp.y] == 0){
                        dist[temp.x][temp.y] = dist[u.x][u.y] + 1;
                        q.push(temp);
                    }
                    if(dist[temp.x][temp.y] != dist[u.x][u.y] + 1){
                        break;
                    }
                    temp.x += fx[i];
                    temp.y += fy[i];
                }
            }
        }
        printf("%d\n", dist[destination.x][destination.y] - 1);
    }

    return 0;
}
