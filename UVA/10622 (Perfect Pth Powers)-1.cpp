#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <cstring>
#define MAX 100005
using namespace std;

typedef long long ll;

ll primes[MAX/10], counter = 0;
bool mark[MAX];

int gcd(int a, int b)
{
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

void genSieve()
{
    int limit = sqrt(MAX + 1);

    mark[1] = true;
    for(int i = 4; i < MAX; i += 2)
        mark[1] = true;

    primes[counter++] = 2;

    for(int i = 3; i < MAX; i += 2){
        if(!mark[i]){
            primes[counter++] = (ll) i;
            if(i <= limit){
                for(int j = i * i; j < MAX; j += i * 2)
                    mark[j] = true;
            }
        }
    }
}

int factorize(ll n)
{
    ll idx = 0, pf = primes[idx];
    int g = 0, cnt = 0;

    while(pf * pf <= n){
        int cnt = 0;
        if(n % pf == 0){
            while(n % pf == 0){
                n /= pf;
                cnt++;
            }
            g = gcd(g, cnt);
        }
        pf = primes[++idx];
    }

    if(n != 1)
        g = gcd(g, 1);

    return g;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    genSieve();
    ll n;

    while(scanf("%lld", &n) == 1){
        if(!n)
            break;
        ll temp = n;
        if(n < 0)
            n = -n;
        int result = factorize(n);
        if(temp < 0 && result % 2 == 0){
            while(result % 2 == 0)
                result /= 2;
        }
        printf("%d\n", result);
    }

    return 0;
}
