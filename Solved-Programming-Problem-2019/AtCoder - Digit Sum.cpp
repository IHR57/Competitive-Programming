//Problem ID: AtCoder - Digit Sum
//Programmer: IQBAL HOSSAIN     Description: Dynamic Programming (Digit-DP)
//Date: 17/01/19
//Problem Link: https://atcoder.jp/contests/dp/tasks/dp_s
#include <bits/stdc++.h>
#define MAX 10005
#define MOD 1000000007
using namespace std;

typedef long long ll;

ll dp[MAX][105][2];
int d, lim;
vector<int> digit;

ll solve(int pos, int rem, int isSmall)
{
    if(pos == lim){
        if(!rem)    return 1;
        return 0;
    }

    if(dp[pos][rem][isSmall] != -1){
        return dp[pos][rem][isSmall];
    }

    int last = (isSmall) ? 9 : digit[pos];

    ll ret = 0;
    for(int i = 0; i <= last; i++){
        ret += solve(pos + 1, (rem + i) % d, isSmall | i < digit[pos]) % MOD;
    }

    dp[pos][rem][isSmall] = ret % MOD;

    return dp[pos][rem][isSmall] % MOD;
}

int main()
{
    char str[MAX];

    scanf("%s", str);
    scanf("%d", &d);

    int len = strlen(str);

    for(int i = 0; i < len; i++){
        digit.push_back(str[i] - 48);
    }
    lim = digit.size();

    memset(dp, -1, sizeof(dp));

    ll result = solve(0, 0, 0);
    result--;
    if(result < 0)
        result += MOD;
    result = result % MOD;
    printf("%lld\n", result);

    return 0;
}
