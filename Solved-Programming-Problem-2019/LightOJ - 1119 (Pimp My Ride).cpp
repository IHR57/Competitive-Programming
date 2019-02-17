//Problem ID: LightOJ - 1119 (Pimp My Ride)
//Programmer: IQBAL HOSSAIN     Description: Dynamic Programming (BitMask)
//Date: 12/02/19
#include <bits/stdc++.h>
#define MAX 15
using namespace std;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}
const int inf = 2147483647;

int dp[1<<MAX], cost[MAX][MAX], n;

int solve(int mask)
{
    if(mask == (1<<n) - 1)
        return 0;
    if(dp[mask] != -1)
        return dp[mask];

    int Min = inf;
    for(int i = 0; i < n; i++){
        int sum = 0;
        if(!check(mask, i)){
            sum = cost[i][i];
            for(int j = 0; j < n; j++){
                if(i != j && check(mask, j)){
                    sum += cost[i][j];
                }
            }
            int ret = solve(Set(mask, i)) + sum;
            Min = min(Min, ret);
        }
    }
    dp[mask] = Min;

    return dp[mask];
}

int main()
{
    int test, caseno = 1;

    scanf("%d", &test);

    while(test--){
        scanf("%d",  &n);
        for(int i = 0; i < n ; i++){
            for(int j = 0; j < n ; j++){
                scanf("%d", &cost[i][j]);
            }
        }

        memset(dp, -1, sizeof(dp));

        int result = solve(0);

        printf("Case %d: %d\n", caseno++, result);
    }

    return 0;
}
