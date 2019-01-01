#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#define MAX 100005
#define MOD 1000000007
using namespace std;

typedef long long ll;

ll f1(ll n)
{
    n = n - 1;
    return ((n * (n + 1)) % MOD) / 2;
}

ll f2(ll n)
{
    n = n - 2;
    return (((n * (n + 1)) % MOD * (n + 2)) % MOD) / 6;
}

ll f3(ll n)
{
    return ((((n * (n - 1)) % MOD * (n - 2)) %MOD * (n - 3)) % MOD) / 24;
}

int main()
{
    int test;
    ll n;

    scanf("%d", &test);

    while(test--){
        scanf("%lld", &n);
        ll sum = 0;
        if(n <= 5){
            printf("%lld\n", (1LL<<(n - 1)));
            continue;
        }
        n = n - 1;
        sum += n + 1;
        sum = (sum + f1(n)) % MOD;
        sum = (sum + f2(n)) % MOD;
        sum = (sum + f3(n)) % MOD;

        printf("%lld\n", sum);
    }

    return 0;
}
