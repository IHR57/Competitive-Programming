//Problem ID: HackerRank - Chessboard Game, Again!
//Programmer: IQBAL HOSSAIN     Description: Game Theory (Grundy Numbers)
//Date: 09/05/19
//Problem Link: https://www.hackerrank.com/challenges/chessboard-game-again-1
#include <bits/stdc++.h>
#define MAX 20
using namespace std;

const int inf = 10;
int dp[MAX][MAX];

int fx[] = { -2, -1, -2, +1 };
int fy[] = { -1, -2, +1, -2 };

int solve(int i, int j)
{
    if(i > 15 || i < 1 || j > 15 || j < 1)
        return inf;
    if(dp[i][j] != -1)
        return dp[i][j];

    int arr[MAX] = {0};
    for(int k = 0; k < 4; k++){
        int g = solve(i + fx[k], j + fy[k]);
        if(g <= 10)
            arr[g] = 1;
    }
    for(int k = 0; k < 10; k++){
        if(arr[k] == 0){
            return dp[i][j] = k;
        }
    }
    return 0;
}
int main()
{
    memset(dp, -1, sizeof(dp));

    int res = solve(15, 15);
    for(int i = 1; i <= 15; i++){
        for(int j = 1; j <= 15; j++){
            if(dp[i][j] == -1){
                int arr[MAX] = {0};
                int res = solve(i, j);
            }
        }
    }

    int test, x, y, n;

    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);
        int ans = 0;
        for(int i = 0; i < n; i++){
            scanf("%d %d", &x, &y);
            ans ^= dp[x][y];
        }
        (ans) ? printf("First\n") : printf("Second\n");
    }

    return 0;
}
