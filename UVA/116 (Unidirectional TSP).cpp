#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#define MAX 105
using namespace std;

typedef long long ll;

int dp[MAX][MAX], grid[MAX][MAX];
int parent[MAX][MAX];
int row, col;

int main()
{
    while(scanf("%d %d", &row, &col) == 2){
        for(int i = 1; i <= row; i++){
            for(int j = 1; j <= col; j++){
                scanf("%d", &grid[i][j]);
            }
        }

        for(int i = 1; i <= row; i++){
            dp[i][col] = grid[i][col];
        }

        for(int j = col - 1; j >= 1; j--){
            for(int i = 1; i <= row; i++){
                dp[i][j] = grid[i][j] + dp[i][j+1];
                parent[i][j] = i;

                int k;
                if(i == 1)      //if it is first row
                    k = row;
                else
                    k = i - 1;
                int value = grid[i][j] + dp[k][j+1];
                if(value < dp[i][j] || (value == dp[i][j] && k < parent[i][j])){
                    dp[i][j] = value;
                    parent[i][j] = k;
                }

                if(i == row)          //if it is last row
                    k = 1;
                else
                    k = i + 1;
                value = grid[i][j] + dp[k][j+1];
                if(value < dp[i][j] || (value == dp[i][j] && k < parent[i][j])){
                    dp[i][j] = value;
                    parent[i][j] = k;
                }
            }
        }
        int temp = dp[1][1];
        int idx = 1;
        for(int i = 2; i <= row; i++){
            if(dp[i][1] < temp){
                temp = dp[i][1];
                idx = i;
            }
        }
        printf("%d", idx);
        idx = parent[idx][1];
        for(int i = 2; i <= row; i++){
            printf(" %d", idx);
            idx = parent[idx][i];
        }
        printf("\n");
        printf("%d\n", temp);
    }

    return 0;
}
