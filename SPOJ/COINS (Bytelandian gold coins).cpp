#include <bits/stdc++.h>
#define MAX 1000005
using namespace std;

typedef long long ll;
ll Max;
map<int, ll>dp;

ll solve(int n)
{
    if(n == 0)
        return 0;
    if(dp[n] != 0)
        return dp[n];
    ll temp = (solve(n/2) + solve(n/3) + solve(n/4));
    if(temp > n){
        dp[n] = temp;
    }
    else
        dp[n] = n;

    return dp[n];
}

int main()
{
    int n;

    while(scanf("%d", &n) == 1){
        ll result = solve(n);
        printf("%lld\n", result);
    }

    return 0;
}
