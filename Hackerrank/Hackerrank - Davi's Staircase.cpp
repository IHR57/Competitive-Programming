//Problem ID: HackerRank - Davi's Staircase
//Programmer: IQBAL HOSSAIN     Description: Recursion/DP
//Date: 11/05/19
#include <bits/stdc++.h>
#define MAX 100005
#define MOD 1000000007
using namespace std;

typedef long long ll;
int coin[] = {1, 2, 3}, n;

ll dp[50];

ll solve(int x)
{
    if(x >= n){
        if(x == n)
            return 1;
        return 0;
    }
    if(dp[x] != -1)
        return dp[x];
    ll ret = 0;
    for(int i = 0; i < 3; i++){
        ret = (ret + solve(x + coin[i]));
    }

    return dp[x] = ret;
}

int main()
{
    int test;

    scanf("%d", &test);

    while(test--){
        scanf("%d",  &n);
        memset(dp, -1, sizeof(dp));
        ll res = solve(0);
        printf("%lld\n", res);
    }

    return 0;
}
