#include <bits/stdc++.h>
#define MAX 105
using namespace std;

int dp[MAX][MAX];

int main()
{
    int row, col, arr[MAX][MAX], test;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &row, &col);
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                scanf("%d", &arr[i][j]);
            }
        }

        for(int i = 0; i < col; i++){
            dp[0][i] = arr[0][i];
        }

        for(int i = 1; i < row; i++){
            for(int j = 0; j < col; j++){
                if(j == 0 && j + 1 != col){
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j+1]) + arr[i][j];
                }
                else if((j == 0 && j + 1 == col) || (j == col - 1 && j - 1 < 0)){
                    dp[i][j] = dp[i-1][j] + arr[i][j];
                }
                else if(j == col - 1 && j - 1 >= 0){
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + arr[i][j];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], max(dp[i-1][j-1], dp[i-1][j+1])) + arr[i][j];
                }
            }
        }

        int Max = -1;
        for(int i = 0; i < col; i++){
            if(dp[row-1][i] > Max)
                Max = dp[row-1][i];
        }

        printf("%d\n", Max);
    }

    return 0;
}
