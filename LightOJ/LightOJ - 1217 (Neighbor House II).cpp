//Problem ID: LightOJ - 1217 (Neighbor House II)
//Programmer: IQBAL HOSSAIN     Description: Dynamic Programming
//Date: 19/02/19
//Problem Link: http://lightoj.com/volume_showproblem.php?problem=1217
#include <bits/stdc++.h>
#define MAX 1005
using namespace std;

typedef long long ll;

int cost[MAX], dp[MAX], n;

int solve(int pos)
{
    if(pos >= n)
        return 0;
    if(dp[pos] != -1)
        return dp[pos];

    int p1 = cost[pos] + solve(pos + 2);
    int p2 = solve(pos + 1);

    dp[pos] = max(p1, p2);

    return dp[pos];
}

int main()
{
    int test, caseno = 1;

    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%d", &cost[i]);
        }

        if(n == 2){
            printf("Case %d: %d\n", caseno++, max(cost[0], cost[1]));
            continue;
        }
        memset(dp, -1, sizeof(dp));

        int result1 = solve(1);
        n--;
        memset(dp, -1, sizeof(dp));
        int result2 = solve(0);

        printf("Case %d: %d\n", caseno++, max(result1, result2));
    }

    return 0;
}
