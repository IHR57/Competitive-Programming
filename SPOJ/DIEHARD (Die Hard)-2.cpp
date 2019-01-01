#include <bits/stdc++.h>
#define MAX 2005
using namespace std;

int dp[MAX][MAX][3];

int solve(int h, int a, int idx)
{
    if(h <= 0 || a <= 0)
        return 0;
    if(dp[h][a][idx] != -1)
        return dp[h][a][idx];

    if(idx == 0){
        dp[h][a][idx] = max(solve(h - 5, a - 10, (idx + 1) % 3), solve(h-20, a+5, (idx+2) % 3)) + 1;
    }
    else if(idx == 1){
        dp[h][a][idx] = max(solve(h-20, a+5, (idx + 1) % 3), solve(h+3, a+2, (idx+2) % 3)) + 1;
    }
    else if(idx == 2){
        dp[h][a][idx] = max(solve(h+3, a+2, (idx + 1) % 3), solve(h-5, a-10, (idx+2) % 3)) + 1;
    }

    return dp[h][a][idx];
}

int main()
{
    int  test, health, armor;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &health, &armor);

        int Max = 0;

        memset(dp, -1, sizeof(dp));
        int ans1 = solve(health + 3, armor + 2, 0);
        memset(dp, -1, sizeof(dp));
        int ans2 = solve(health - 5, armor - 10, 1);
        memset(dp, -1, sizeof(dp));
        int ans3 = solve(health - 20, armor + 5, 2);

        int result = max(ans1, max(ans2, ans3));

        printf("%d\n", result);
    }

    return 0;
}
