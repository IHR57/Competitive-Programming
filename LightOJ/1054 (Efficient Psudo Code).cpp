#include <bits/stdc++.h>
#define MAX 1000005
#define MOD 1000000007
using namespace std;

typedef long long ll;

ll primes[MAX / 10], counter = 0, m;
bool mark[MAX];

ll bigMod(ll a, ll b)
{
    if(b == 0)
        return 1 % MOD;
    ll x = bigMod(a, b/2);
    x = (x * x) % MOD;
    if(b % 2 == 1)
        x = (x * a) % MOD;
    return x;
}

void genSieve()
{
    int limit = (int) sqrt(MAX + 1);

    mark[1] = true;
    for(int i = 4; i < MAX; i += 2)
        mark[i] = true;

    primes[counter++] = 2;

    for(int i = 3; i < MAX; i += 2){
        if(!mark[i]){
            primes[counter++] = i;
            if(i <= limit){
                for(int j = i * i; j < MAX; j += i * 2)
                    mark[j] = true;
            }
        }
    }
}

ll sumDiv(ll n)
{
    ll idx = 0, pf = primes[idx], ans = 1;

    while(pf * pf <= n){
        ll cnt = 0;
        while(n % pf == 0){
            cnt++;
            n /= pf;
        }
        ll p = (cnt * m);
        ans *= (((bigMod(pf, p + 1) - 1) % MOD) * (bigMod((pf-1), MOD - 2) % MOD)) % MOD;
        ans %= MOD;
        pf = primes[++idx];
    }
    if(n != 1){
        ans *= (((bigMod(n, m + 1) - 1) % MOD) * (bigMod((n-1), MOD - 2) % MOD)) % MOD;
        ans %= MOD;
    }

    return ans % MOD;
}

int main()
{
    genSieve();
    ll n, test, caseNo = 1;

    scanf("%lld", &test);

    while(test--){
        scanf("%lld %lld", &n, &m);
        ll result = sumDiv(n);
        if(result < 0)
            result = MOD + result;
        printf("Case %lld: %lld\n", caseNo++, result);
    }

    return 0;
}
