#include <bits/stdc++.h>
#define MAX 1005
using namespace std;

typedef long long ll;

ll MOD;

ll bigMod(ll a, ll b)
{
    if(b == 0)
        return 1;
    ll x = bigMod(a, b/2);
    x = (x * x) % MOD;
    if(b % 2 == 1)
        x = (x * a) % MOD;

    return x;
}

ll solve(ll n, ll k)
{
    return (bigMod(n, k-1) * k) % MOD;
}

int main()
{
    int test, caseno = 1;
    ll arr[MAX], n, k;

    scanf("%d", &test);

    while(test--){
        scanf("%lld %lld %lld", &n, &k, &MOD);
        for(int i = 0; i < n; i++){
            scanf("%lld", &arr[i]);
        }
        ll sum = 0;
        ll val = solve(n, k);
        for(int i = 0; i < n; i++){
            sum = (sum + arr[i] * val) % MOD;
        }

        printf("Case %d: %lld\n", caseno++, sum);
    }

    return 0;
}
