#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#define MAX 3000005
#define MOD 1000000007
using namespace std;

typedef long long ll;
vector<ll> primes;
vector<bool> mark(MAX, false);

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

void genSieve()
{
    int limit = (int) sqrt(MAX) + 1;
    mark[1] = true;

    for(int i = 4; i < MAX; i += 2)
        mark[i] = true;

    primes.push_back(2);

    for(int i = 3; i < MAX; i += 2){
        if(!mark[i]){
            primes.push_back(i);
            if(i <= limit){
                for(int j = i * i; j < MAX; j += i * 2)
                    mark[j] = true;
            }
        }
    }
}

int main()
{
    genSieve();

    int query, k;

    scanf("%d", &query);

    while(query--){
        scanf("%d", &k);
        k--;
        ll ans = bigMod(primes[k], primes[k]);
        printf("%lld\n", ans);
    }

    return 0;
}

