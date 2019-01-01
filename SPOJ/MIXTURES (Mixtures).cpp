#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

ll dp[105][105];
int arr[105];
const int inf = 1<<28;

int cs(int i, int j)
{
    int sum = 0;
    for(int k = i; k <= j; k++){
        sum += arr[k];
        sum %= 100;
    }

    return sum;
}

ll solve(int i, int j)
{
    if(i > j || i == j)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];

    dp[i][j] = inf;
    for(int k = i; k < j; k++){
        dp[i][j] =  min(dp[i][j], solve(i, k) + solve(k + 1, j) + cs(i, k) * cs(k + 1, j));
    }

    return dp[i][j];
}

int main()
{
    int n;
    while(scanf("%d", &n) == 1){
        for(int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
        }
        memset(dp, -1, sizeof(dp));
        ll result = solve(0, n - 1);
        printf("%lld\n", result);
    }

    return 0;
}
