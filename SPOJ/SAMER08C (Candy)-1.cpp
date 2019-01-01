#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int m, n, dp[MAX];

int solve(int a[], int i, int n)
{
    if(i >= n)
        return 0;
    if(dp[i])
        return dp[i];

    int profit1 = 0, profit2 = 0;

    profit1 = a[i] + solve(a, i + 2, n);
    profit2 = solve(a, i + 1, n);

    dp[i] = max(profit1, profit2);

    return dp[i];
}

int main()
{
    int arr[MAX], cost[MAX];

    while(scanf("%d %d", &m, &n) == 2){
        if(!m && !n)    break;
        for(int i = 0; i < m; i++){
            fill(dp, dp + n, 0);
            for(int j = 0; j < n; j++){
                scanf("%d", &arr[j]);
            }
            cost[i] = solve(arr, 0, n);
        }

        fill(dp, dp + m, 0);
        int result = solve(cost, 0, m);

        printf("%d\n", result);
    }

    return 0;
}
