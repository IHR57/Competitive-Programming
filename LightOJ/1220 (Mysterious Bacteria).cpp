#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

ll primes[MAX/10], mark[MAX], counter = 0;

void genSieve()
{
    ll limit = sqrt(MAX);

    mark[1] = 1;
    for(ll i = 4; i < MAX; i += 2)
        mark[i] = 1;

    primes[counter++] = 2;

    for(ll i = 3; i < MAX; i += 2){
        if(!mark[i]){
            primes[counter++] = i;
            if(i <= limit){
                for(ll j = i * i; j < MAX; j += i * 2)
                    mark[j] = 1;
            }
        }
    }
}

vector<ll> primeFactor(ll n)
{
    vector<ll> v;

    ll idx = 0, pf = primes[idx], cnt, c = 0;
    while(pf * pf <= n){
        cnt = 0;
        while(n % pf == 0){
            cnt++;
            n /= pf;
        }
        pf = primes[++idx];
        if(cnt)
            v.push_back(cnt);
    }
    if(n != 1){
        v.push_back(1);
    }

    return v;
}

int main()
{
    genSieve();
    ll test, caseNo = 1, n;

    scanf("%d", &test);

    while(test--){
        scanf("%lld", &n);
        ll temp = n;
        if(temp < 0)
            temp = -temp;
        vector<ll> factor = primeFactor(temp);
        ll g = factor[0];
        for(ll i = 1; i < factor.size(); i++){
            g = __gcd(g, factor[i]);
        }

        if(n < 0 && g % 2 == 0){
            while(g % 2 == 0){
                g /= 2;
            }
        }
        printf("Case %lld: %lld\n", caseNo++, g);
    }

    return 0;
}
