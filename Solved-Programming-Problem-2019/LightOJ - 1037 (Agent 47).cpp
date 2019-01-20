//Problem ID: LightOJ - 1037 (Agent 47)
//Programmer: IQBAL HOSSAIN     Description: Dynamic Programming (Bitmask-DP)
//Date: 19/01/19
//Problem Link: http://lightoj.com/volume_showproblem.php?problem=1037
#include <bits/stdc++.h>
#define MAX 15
using namespace std;

typedef long long ll;

ll dp[(1<<MAX) + 10];
int n, health[MAX], cost[MAX][MAX];
const int inf = 1<<28;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

ll solve(int mask)
{
    if(mask == (1<<n) - 1){
        return 0;
    }

    if(dp[mask] != -1)
        return dp[mask];

    ll Min = 1e14;

    for(int i = 0; i < n; i++){
        if(!check(mask, i)){
            int Max = 1;
            for(int j = 0; j < n; j++){
                if(i != j && check(mask, j)){
                    Max = max(Max, cost[j][i]);
                }
            }
            int temp = (health[i] % Max == 0) ? (health[i] / Max) : (health[i] / Max) + 1;

            ll ret = (ll) temp + solve(Set(mask, i));
            Min = min(Min, ret);
        }
    }
    dp[mask] =  Min;

    return dp[mask];
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int test, caseno = 1;
    char str[MAX+10];
    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%d", &health[i]);
        }
        for(int i = 0; i < n; i++){
            scanf("%s", str);
            for(int j = 0; j < n; j++){
                cost[i][j] = str[j] - 48;
            }
        }

        memset(dp, -1, sizeof(dp));

        ll result = solve(0);

        printf("Case %d: %lld\n", caseno++, result);
    }

    return 0;
}
