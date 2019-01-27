//Problem ID: LightOJ - 1064 (Throwing Dice)
//Programmer: IQBAL HOSSAIN     Description: Dynamic Programming
//Date: 27/01/19
//Problem Link: http://lightoj.com/volume_showproblem.php?problem=1064
#include <bits/stdc++.h>
#define MAX 160
using namespace std;

typedef long long ll;

ll dp[MAX][30];
int n, x;

ll Power(ll a, ll b)
{
    if(b == 0)
        return 1;
    ll x = Power(a, b / 2);
    x = (x * x);
    if(b % 2 == 1){
        x = (x * a);
    }
    return x;
}

ll solve(int amnt, int pos)
{
    if(pos == n){
        if(amnt >= x)
            return 1;
        return 0;
    }
    if(dp[amnt][pos] != -1)
        return dp[amnt][pos];

    ll ret = 0;
    for(int i = 1; i <= 6; i++){
        ret += solve(amnt + i, pos + 1);
    }

    return dp[amnt][pos] = ret;
}

int main()
{
    int test, caseno = 1;
    scanf("%d", &test);

    for(int i = 0; i < test; i++){
        scanf("%d %d", &n, &x);

        memset(dp, -1, sizeof(dp));

        ll numberOfOutcomes = solve(0, 0);
        ll total = Power(6, (ll) n);

        ll g = __gcd(numberOfOutcomes, total);
        numberOfOutcomes /= g;
        total /= g;
        if(total == 1){
            printf("Case %d: %lld\n", caseno++, numberOfOutcomes);
        }
        else{
            printf("Case %d: %lld/%lld\n", caseno++, numberOfOutcomes, total);
        }
    }

    return 0;
}
