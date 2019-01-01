#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#define MAX 1000005
#define MOD 1000000007
using namespace std;

typedef long long ll;

ll factorial[2*MAX];

ll bigMod(ll a, ll b)
{
    if(b == 0)
        return 1;
    ll x = bigMod(a, b/2);
    x = (x * x) % MOD;
    if(b % 2 == 1){
        x = (x * a) % MOD;
    }

    return x;
}

ll calculate(int n, int k)
{
    return (factorial[n] * ((bigMod(factorial[k], MOD - 2) * bigMod(factorial[n-k], MOD - 2)) % MOD)) % MOD;
}

int main()
{
    int test, caseNo = 1, n, k;

    factorial[0] = 1;
    for(int i = 1; i < 2*MAX; i++){
        factorial[i] = (i * factorial[i-1]) % MOD;
    }

    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &n, &k);
        ll result = calculate(n + k - 1, k - 1);
        printf("Case %d: %lld\n", caseNo++, result);
    }

    return 0;
}
