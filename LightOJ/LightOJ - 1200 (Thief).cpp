//Problem ID: LightOJ - 1200 (Thief)
//Programmer: IQBAL HOSSAIN     Description: Dynamic Programming (Modified Knapsack)
//Date: 19/02/19
//Problem Link: http://lightoj.com/volume_showproblem.php?problem=1200
#include <bits/stdc++.h>
#define MAX 10005
using namespace std;

int dp[105][MAX];
int price[105], weight[105], c[105], n, cap;

int solve(int pos, int w)
{
    if(pos >= n)
        return 0;
    if(dp[pos][w] != -1)
        return dp[pos][w];

    int profit1 = 0, profit2 = 0, profit3 = 0;
    if(w + weight[pos] <= cap){
        profit1 = price[pos] + solve(pos, w + weight[pos]);
        profit2 = price[pos] + solve(pos + 1, w + weight[pos]);
    }
    profit2 = solve(pos + 1, w);

    dp[pos][w] = max(profit1, max(profit2, profit3));

    return dp[pos][w];
}

int main()
{
    int test, caseno = 1;
    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &n, &cap);

        for(int i = 0; i < n ; i++){
            scanf("%d %d %d", &price[i], &c[i],  &weight[i]);
            cap -= (c[i] * weight[i]);
        }
        if(cap < 0){
            printf("Case %d: Impossible\n", caseno++);
            continue;
        }
        memset(dp, -1, sizeof(dp));
        int result = solve(0, 0);

        printf("Case %d: %d\n", caseno++, result);
    }

    return 0;
}
