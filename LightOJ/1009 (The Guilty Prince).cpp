#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <queue>
#define MAX 25
using namespace std;

struct PII
{
    int u, v;
};

int fx[] = {1, -1, 0, 0};     //direction array
int fy[] = {0, 0, 1, -1};     //direction array
int cell[MAX][MAX], visited[MAX][MAX];
int row, col;       //number of row and column

void init()
{
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            cell[i][j] = 0;
        }
    }
}

int breadthFirst(int sx, int sy)
{
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            visited[i][j] = 0;
        }
    }

    visited[sx][sy] = 1;        //the source initialized as visited

    PII pi;
    int count = 1;

    queue<PII> q;       //A queue containing STL Pairs
    pi.u = sx;
    pi.v = sy;

    q.push(pi);

    while(!q.empty()){
        PII pp;
        pp = q.front();
        q.pop();

        for(int k = 0; k < 4; k++){
            int tx = pp.u + fx[k];
            int ty = pp.v + fy[k];      //Neighbour cell
            //check if the neighbour cell is valid
            if(tx >= 0 && tx < row && ty >= 0 && ty < col && cell[tx][ty] == 1 && visited[tx][ty] == 0)
            {
                PII get;
                visited[tx][ty] = 1;
                count++;
                get.u = tx;
                get.v = ty;
                q.push(get);
            }
        }
    }

    return count;
}

int main()
{
    int x, y, test, cases = 1;
    char str[100];

    scanf("%d", &test);

    while(test--){
        init();
        scanf("%d %d", &col, &row);
        for(int i = 0; i < row; i++){
            scanf("%s", &str);
            for(int j = 0; j < col; j++){
                if(str[j] == '.')
                    cell[i][j] = 1;
                else if(str[j] == '@'){
                    x = i;
                    y = j;
                    cell[i][j] = 1;
                }
            }
        }
        int result = breadthFirst(x, y);

        printf("Case %d: %d\n", cases++, result);
    }

    return 0;
}
