#include <bits/stdc++.h>
#define MAX 5005
using namespace std;

char str[MAX];
int dp[MAX][MAX];

int solve(int i, int j)
{
    if(i > j)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];

    if(str[i] == str[j]){
        dp[i][j] = solve(i+1, j-1);
    }
    else if(str[i] != str[j]){
        dp[i][j] = min(solve(i, j-1), solve(i+1, j)) + 1;
    }

    return dp[i][j];
}

int main()
{
    int n;

    scanf("%d", &n);
    scanf("%s", str);

    memset(dp, -1, sizeof(dp));

    int len = strlen(str);
    int result = solve(0, len-1);

    printf("%d\n", result);
}
