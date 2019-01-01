#include <bits/stdc++.h>
#define MAX 105
using namespace std;

int dp[MAX][MAX], arr[MAX];
const int inf = 1<<28;

int solve(int l, int r)
{
    if(l > r)
        return 0;
    if(dp[l][r] != -1)
        return dp[l][r];

    int sum = 0, Max = -inf;

    for(int i = l; i <= r; i++){
        sum += arr[i];
        Max = max(Max, sum - solve(i + 1, r));
    }

    sum = 0;
    for(int i = r; i >= l; i--){
        sum += arr[i];
        Max = max(Max, sum - solve(l, i - 1));
    }

    dp[l][r] = Max;

    return dp[l][r];
}

int main()
{
    int test, caseno = 1, n;

    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
        }

        memset(dp, -1, sizeof(dp));
        int result = solve(0, n - 1);

        printf("Case %d: %d\n", caseno++, result);
    }

    return 0;
}
