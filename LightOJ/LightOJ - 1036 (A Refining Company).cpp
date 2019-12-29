//Problem ID: LightOJ - 1036 (A Refining Company)
//Programmer: IQBAL HOSSAIN     Description: Dynamic Programming
//Date: 20/03/19
//Problem Link: http://www.lightoj.com/volume_showproblem.php?problem=1036
#include <bits/stdc++.h>
#define MAX 505
using namespace std;

int north[MAX][MAX], west[MAX][MAX];
int dp[MAX][MAX];

int solve(int i, int j)
{
    if(i < 0 || j < 0)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];

    int ret1 = 0, ret2 = 0;
    ret1 = west[i][j] + solve(i - 1, j);
    ret2 = north[i][j] + solve(i, j - 1);

    dp[i][j] = max(ret1, ret2);

    return dp[i][j];
}

int main()
{
    int test, caseno = 1, n, m;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &n, &m);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                scanf("%d", &west[i][j]);
                if(j > 0)
                    west[i][j] += west[i][j-1];     //consecutive row sum
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                scanf("%d", &north[i][j]);
                if(i > 0)
                    north[i][j] += north[i-1][j];       //consecutive column sum
            }
        }

        memset(dp, -1, sizeof(dp));
        int result = solve(n - 1, m - 1);

        printf("Case %d: %d\n", caseno++, result);
    }

    return 0;
}
