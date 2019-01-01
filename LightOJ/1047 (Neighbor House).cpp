#include <bits/stdc++.h>
#define MAX 105
using namespace std;

int n, cost[MAX][MAX], dp[MAX][MAX];
const int inf = 1<<28;

int solve(int i, int j)
{
    if(i == n)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];

    int ans = inf;
    for(int k = 0; k < 3; k++){
        if(k != j){
            ans = min(ans, cost[i][j] + solve(i+1, k));
            //cout<<ans<<endl;
        }
    }
    //cout<<ans<<endl;
    dp[i][j] = ans;
    return dp[i][j];
}

int main()
{
    int test, caseNo = 1;

    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < 3; j++){
                scanf("%d", &cost[i][j]);
            }
        }

        memset(dp, -1, sizeof(dp));

        int result = inf;
        for(int i = 0; i < 3; i++){
            result = min(result, solve(0, i));
        }

        printf("Case %d: %d\n", caseNo++, result);
    }

    return 0;
}
