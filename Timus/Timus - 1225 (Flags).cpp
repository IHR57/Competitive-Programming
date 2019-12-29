//Problem ID: TIMUS - 1225 (Flags)
//Programmer: IQBAL HOSSAIN     Description: Dynamic Programming
//Date: 18/07/19
#include <bits/stdc++.h>
#define MAX 200005
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ll dp[50];
    int n;

    scanf("%d", &n);
    dp[0] = 0, dp[1] = 2;
    for(int i = 2; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    printf("%lld\n", dp[n]);

    return 0;
}