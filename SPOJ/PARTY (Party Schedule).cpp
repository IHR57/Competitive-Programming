#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#define MAX 505
using namespace std;

int dp[MAX][MAX], weight[MAX], cost[MAX], capacity, Max, n;

int main()
{
    while(scanf("%d %d", &capacity, &n) == 2){
        if(!capacity && !n)
            break;
        for(int i = 1; i <= n; i++){
            scanf("%d %d", &weight[i], &cost[i]);
        }

        Max = -1;
        memset(dp, 0, sizeof(dp));

        for(int i = 1; i <= n; i++){
            for(int w = 1; w <= capacity; w++){
                if(w < weight[i])
                    dp[i][w] = dp[i-1][w];
                else{
                    dp[i][w] = max(dp[i-1][w], dp[i-1][w - weight[i]] + cost[i]);
                }
            }
        }

        for(int i = 1; i <= capacity; i++){
            if(dp[n][i] == dp[n][capacity]){
                Max = i;
                break;
            }
        }
        printf("%d %d\n", Max, dp[n][capacity]);
    }

    return 0;
}
