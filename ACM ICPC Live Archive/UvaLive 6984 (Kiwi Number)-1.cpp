#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#define MAX 1000005
using namespace std;

typedef long long ll;

int mark[MAX], counter = 0;
ll primes[80000];
vector<bool> isPrime;

void genSieve()
{
    int limit = (int) sqrt(MAX) + 1;
    mark[1] = 1;
    for(int i = 4; i < MAX; i += 2)
        mark[i] = 1;

    primes[counter++] = 2;

    for(int i = 3; i < MAX; i += 2){
        if(!mark[i]){
            primes[counter++] = i;
            if(i <= limit){
                for(int j = i * i; j < MAX; j += i * 2){
                    mark[j] = 1;
                }
            }
        }
    }
}
int SegmentedSieve(ll a, ll b)
{
    int cnt = 0;
    isPrime = vector<bool> (b - a + 1, true);

    ll i, j;
    for(i = 0; primes[i] * primes[i] <= b && i < counter; i++){
        if(primes[i] != 0){
            j = a / primes[i];
        }
        j *= primes[i];
        for(; j <= b; j+= primes[i]){
            if(j < a || j == primes[i])
                continue;
            isPrime[j-a] = false;
        }
    }

    for(i = 0; i < b - a + 1; i++){
        if(isPrime[i])
            cnt++;
    }

    isPrime.clear();
    return cnt;
}

ll numDiv(ll n)
{
    ll idx = 0, pf = primes[idx], ans = 1;

    while(pf * pf <= n){
        int cnt = 0;
        while(n % pf == 0){
            n /= pf;
            cnt++;
        }
        ans *= (cnt + 1);
        pf = primes[++idx];
    }
    if(n != 1)
        ans *= 2;

    return ans;
}

int main()
{
    genSieve();
    int test;
    ll a, b;

    //cout<<counter<<endl;
    scanf("%d", &test);

    while(test--){
        scanf("%lld %lld", &a, &b);
        int cnt = 0;
        if(a <= 1)
            a = 2;
        ll x = ceil(sqrt(a));
        ll y = sqrt(b);

        for(ll i = x; i <= y; i++){
            ll temp = numDiv(i * i);
            if(!mark[temp])     //number of perfect square
                cnt++;
        }

        cnt += SegmentedSieve(a, b);        //number of prime in the range[a, b]

        printf("%d\n", cnt);
    }

    return 0;
}
