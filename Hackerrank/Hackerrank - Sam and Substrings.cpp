//Problem ID: HackerRank - Sam ans Substrings
//Programmer: IQBAL HOSSAIN     Description: Dynamic Programming
//Date: 17/04/19
#include <bits/stdc++.h>
#define MAX 200005
#define MOD 1000000007
using namespace std;

typedef long long ll;
char str[MAX];
ll dp[MAX];

int main()
{
    scanf("%s", str);
    dp[0] = str[0] - 48;

    int len = strlen(str);

    for(int i = 1; i < len; i++){
        dp[i] = ((dp[i-1] * 10) % MOD + ((i + 1) * (str[i] - 48)) % MOD) % MOD;
    }

    ll ans = 0;
    for(int i = 0; i < len; i++){
        ans = (ans + dp[i]) % MOD;
    }

    printf("%lld\n", ans);

    return 0;
}
