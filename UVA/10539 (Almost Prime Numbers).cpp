#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <cstring>
#define MAX 1000005
using namespace std;

typedef long long ll;

ll primes[80000], counter = 0;
bool mark[MAX];

void genSieve()
{
    int limit = sqrt(MAX + 1);

    mark[1] = true;
    for(int i = 4; i < MAX; i += 2)
        mark[1] = true;

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

int main()
{
    genSieve();

    ll low, high;
    int test;

    scanf("%d", &test);

    while(test--){
        scanf("%lld %lld", &low, &high);
        ll sum = 0;
        for(int i = 0; primes[i] * primes[i] <= high; i++){
            ll ans1 = 0, ans2 = 0;
            ll temp = high;
            ll div = primes[i] * primes[i];
            while(temp / div > 0){
                ans1++;
                div *= primes[i];
            }

            temp = low - 1;
            div = primes[i] * primes[i];
            while(temp / div > 0){
                ans2++;
                div *= primes[i];
            }
            sum += (ans1 - ans2);
        }

        printf("%lld\n", sum);
    }

    return 0;
}
