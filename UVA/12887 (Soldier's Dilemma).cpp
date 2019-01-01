#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#define MAX 5005
#define MOD 1000000007
using namespace std;

typedef long long ll;

ll catalan[MAX];

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

int main()
{
    catalan[0] = 1;

    for(int i = 0; i < MAX; i++){
        catalan[i + 1] = ((2 * (2 * i + 1) * catalan[i]) % MOD * bigMod(i + 2, MOD - 2)) % MOD;
    }

    int test, n;

    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);
        printf("%lld\n", catalan[n]);
    }

    return 0;
}
