#include <bits/stdc++.h>
#define MAX 55
using namespace std;

int dp[MAX][MAX][MAX];

char str1[MAX], str2[MAX], str3[MAX];

int solve(int i, int j, int k)
{
    if(i < 0 || j < 0 || k < 0)
        return 0;
    if(dp[i][j][k] != -1)
        return dp[i][j][k];
    if(str1[i] == str2[j] && str1[i] == str3[k]){
        dp[i][j][k] = 1 + solve(i - 1, j - 1, k - 1);
    }
    else{
        dp[i][j][k] = max(max(solve(i - 1, j, k), solve(i, j - 1, k)), solve(i, j, k - 1));
    }

    return dp[i][j][k];
}

int main()
{
    int test, caseno = 1;

    scanf("%d", &test);

    while(test--){
        scanf("%s", str1);
        scanf("%s", str2);
        scanf("%s", str3);

        int len1 = strlen(str1), len2 = strlen(str2), len3 = strlen(str3);

        memset(dp, -1, sizeof(dp));

        int result = solve(len1-1, len2-1, len3-1);

        printf("Case %d: %d\n", caseno++, result);
    }

    return 0;
}
