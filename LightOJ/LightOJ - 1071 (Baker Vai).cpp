//Problem ID: LightOJ - 1071 (Baker Vai)
//Programmer: IQBAL HOSSAIN     Description: Dynamic Programming
//Date: 12/02/19
#include <bits/stdc++.h>
#define MAX 105
using namespace std;

int dp[MAX][MAX][MAX], cost[MAX][MAX];
int m, n;

int solve(int r1, int c1, int r2, int c2)
{
    if(r1 >= m || c1 >= n || r2 >= m || c2 >= n)
        return 0;
    if(r1 == r2 && c1 == c2){   //we cannot visit a cell twice
        return 0;
    }
    if(dp[r1][c1][c2] != -1)
        return dp[r1][c1][c2];

    int p1 = solve(r1, c1 + 1, r2, c2 + 1);
    int p2 = solve(r1, c1 + 1, r2 + 1, c2);
    int p3 = solve(r1 + 1, c1, r2, c2 + 1);
    int p4 = solve(r1 + 1, c1, r2 + 1, c2);

    dp[r1][c1][c2] = max(max(p1, p2), max(p3, p4)) + cost[r1][c1] + cost[r2][c2];
    //maximum sum possible after reaching r1'th row

    return dp[r1][c1][c2];
}

int main()
{
    int test, caseno = 1;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d",  &m, &n);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                scanf("%d", &cost[i][j]);
            }
        }

        memset(dp, -1, sizeof(dp));

        int result = solve(0, 1, 1, 0);
        result += cost[0][0] + cost[m-1][n-1];

        printf("Case %d: %d\n", caseno++, result);
    }

    return 0;
}
