#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#define MAX 10000020
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

bool mark[MAX];
vector<int> primes;

void genSieve()
{
    int limit = sqrt(MAX);
    mark[1] = true;
    for(int i = 4; i < MAX; i += 2)
        mark[i] = true;

    for(int i = 3; i < MAX; i += 2){
        if(!mark[i]){
            primes.push_back(i);
            if(i <= limit){
                for(int j = i * i; j < MAX; j += i * 2){
                    mark[j] = true;
                }
            }
        }
    }
}

int  solve(ll n)
{
    int idx = 0, ans = 1;
    ll pf = (ll) primes[idx];

    while(pf * pf <= n){
        if(n % pf == 0){
            int cnt = 0;
            while(n % pf == 0){
                n /= pf;
                cnt++;
            }
            ans *= (cnt + 1);
        }
        pf = (ll) primes[++idx];
    }

    while(n % 2 == 0){
        n /= 2;
    }
    if(n != 1)
        ans *= 2;

    return ans - 1;
}

int main()
{
    genSieve();
    ll n;
    int test, caseno = 1;

    scanf("%d", &test);

    while(test--){
        scanf("%lld", &n);

       int result = solve(n);

       printf("Case %d: %d\n", caseno++, result);
    }

    return 0;
}
