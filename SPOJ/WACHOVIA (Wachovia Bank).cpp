#include <bits/stdc++.h>
#define MAX 55
using namespace std;

int cap, weight[MAX], value[MAX], dp[MAX][1005];
int m;

int solve(int i, int w)
{
    if(i == m)
        return 0;
    if(dp[i][w] != -1)
        return dp[i][w];
    int profit1 = 0, profit2 = 0;
    if(w + weight[i] <= cap){
        profit1 = value[i] + solve(i + 1, w + weight[i]);
    }
    profit2 = solve(i + 1, w);

    dp[i][w] = max(profit1, profit2);

    return dp[i][w];
}

int main()
{
    int test;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &cap, &m);
        for(int i = 0; i < m; i++){
            scanf("%d %d", &weight[i], &value[i]);
        }

        memset(dp, -1, sizeof(dp));

        int result = solve(0, 0);

        printf("Hey stupid robber, you can get %d.\n", result);
    }

    return 0;
}
