#include <bits/stdc++.h>
#define MAX 105
using namespace std;

int dp[MAX][MAX], n, w;
int y[MAX];

int solve(int i, int k)
{
    if(i == n)
        return 0;
    if(k == 0)
        return 0;
    if(dp[i][k] != -1)
        return dp[i][k];
    int temp = upper_bound(y, y + n, y[i] + w) - y;
    dp[i][k] = max(temp - i + solve(temp, k-1), solve(i + 1, k));

    return dp[i][k];
}

int main()
{
    int test, caseno = 1, k;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d %d", &n, &w, &k);
        int x;
        for(int i = 0; i < n; i++){
            scanf("%d %d", &x, &y[i]);
        }

        sort(y, y + n);

        memset(dp, -1, sizeof(dp));
        int result = solve(0, k);

        printf("Case %d: %d\n", caseno++, result);
    }

    return 0;
}
