// BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int dp[20][150];

int solve(int n, int k)
{
    if(n == 0)
        return 0;
    if(k == 0)
        return 1;
    if(dp[n][k] != -1)
        return dp[n][k];
    int sum = 0;
    for(int i = 0; i < n && k - i >= 0; i++){
        sum += solve(n-1, k - i);
    }

    dp[n][k] = sum;

    return dp[n][k];
}

int main()
{
    int test, n, k;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &n, &k);
        memset(dp, -1, sizeof(dp));
        int result = solve(n, k);
        printf("%d\n", result);
    }

    return 0;
}
