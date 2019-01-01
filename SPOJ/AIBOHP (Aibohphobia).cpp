#include <bits/stdc++.h>
#define MAX 6105
using namespace std;

char str[MAX];
int dp[MAX][MAX];

int solve(int i, int j)
{
    if(i > j)
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    int ans;
    if(str[i] != str[j]){
        ans = min(solve(i, j - 1), solve(i + 1, j)) + 1;
    }
    else{
        ans = solve(i+1, j-1);
    }

    dp[i][j] = ans;

    return dp[i][j];
}

int main()
{
    int test;

    scanf("%d", &test);

    while(test--){
        scanf("%s", str);
        int len = strlen(str);
        memset(dp, -1, sizeof(dp));
        int result = solve(0, len-1);

        printf("%d\n", result);
    }

    return 0;
}
