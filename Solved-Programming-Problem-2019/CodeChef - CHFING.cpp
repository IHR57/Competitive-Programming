//Problem ID: CodeChef - CHFING (Chef and Ingredients)
//Programmer: IQBAL HOSSAIN     Description: MATH
//Date: 09/06/19
//Problem Link: https://www.codechef.com/JUNE19A/problems/CHFING
#include <bits/stdc++.h>
#define MAX 100005
#define MOD 1000000007
#define INF 1e9
using namespace std;

typedef long long ll;

ll bigMod(ll a, ll b)
{
    if(b == 0)
        return 1;
    ll x = bigMod(a, b / 2);
    x = (x * x) % MOD;
    if(b % 2 == 1)
        x = (x * a) % MOD;
    return x;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int test;
    ll n, k;

    scanf("%d", &test);

    while(test--){
        scanf("%lld %lld", &n, &k);
        ll ans = 0;
        if(k * 2 > k + n - 1){
            ll b = k + n - 1;
            ll temp = k * 2 - b - 1;
            ll a = temp % (n - 1);
            ll m = temp / (n - 1) + 1;
            a %= MOD, m %= MOD, n %= MOD;
            ans = ((m * ((2 * a) % MOD + ((m - 1) * (n - 1)) % MOD) % MOD) % MOD * bigMod(2, MOD - 2)) % MOD;
            if(ans < 0)
                ans += MOD;
            ans %= MOD;
        }
        ans = (ans + (k - 1)) % MOD;
        printf("%lld\n", ans);
    }

    return 0;
}