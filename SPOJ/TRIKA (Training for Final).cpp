#include <bits/stdc++.h>
#define MAX 30
#define INF 1<<28
using namespace std;

int main()
{
    int row, col, x, y, p[MAX][MAX], s[MAX][MAX];

    scanf("%d %d",  &row, &col);
    scanf("%d %d", &x, &y);

    for(int i = 1; i <= row; i++){
        for(int j = 1; j <= col; j++){
            scanf("%d", &p[i][j]);
            s[row][col] = INF;
        }
    }

    for(int i = x; i <= row; i++){
        for(int j = y; j <= col; j++){
            if(i - 1 < x && j - 1 >= y){
                s[i][j] = p[i][j] + s[i][j-1];
            }
            else if(i - 1 >= x && j - 1 < y){
                s[i][j] = p[i][j] + s[i-1][j];
            }
            else if(i - 1 >= x && j - 1 >= y){
                s[i][j] = p[i][j] + min(s[i-1][j], s[i][j-1]);
            }
            else{
                s[i][j] = p[i][j];
            }
        }
    }

    int ans = 2 * p[x][y] - s[row][col];
    if(ans >= 0)
        printf("Y %d\n", ans);
    else{
        printf("N\n");
    }

    return 0;
}
