#include <bits/stdc++.h>
#define MAX 1005
using namespace std;

int n, cap, weight[MAX], dp[MAX][MAX];

int solve(int i, int w)
{
    if(i >= n)
        return 0;
    if(dp[i][w] != -1)
        return dp[i][w];

    int profit1 = 0, profit2 = 0;
    if(w + weight[i] <= cap){
        profit1 = weight[i] + solve(i + 2, w + weight[i]);
    }
    profit2 = solve(i + 1, w);
    dp[i][w] = max(profit1, profit2);

    return dp[i][w];
}

int main()
{
    int test, caseno = 1;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &n, &cap);
        for(int i = 0; i < n; i++){
            scanf("%d", &weight[i]);
        }

        memset(dp, -1, sizeof(dp));

        int result = solve(0, 0);

        printf("Scenario #%d: %d\n", caseno++, result);
    }

    return 0;
}
