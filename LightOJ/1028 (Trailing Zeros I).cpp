#include <iostream>
#include <math.h>
#include <algorithm>
#include <cstdio>
#define MAX 1000010
using namespace std;

int primes[70000], counter = 0;
bool mark[MAX];

typedef long long int lint;

void genSieve()
{
    int limit = sqrt(MAX + 1);

    mark[1] = 1;

    for(int i = 4; i < MAX; i += 2)
        mark[i] = 1;

    primes[counter++] = 2;

    for(int i = 3; i < MAX; i += 2){
        if(!mark[i]){
            primes[counter++] = i;
            if(i <= limit){
                for(int j = i * i; j < MAX; j += i * 2)
                    mark[j] = 1;
            }
        }
    }
}

lint numDiv(lint n)     //return number of divisor of n
{
    int i = 0;
    lint pf = primes[i],  ans = 1;

    while(pf * pf <= n){
        int count = 0;
        while(n % pf == 0){
            n = n / pf;
            count++;
        }
        ans *= (count + 1);     //formula for finding number of divisor
        pf = primes[++i];
    }
    if(n != 1)      //if it is a prime number
        ans *= 2;

    return ans;
}

int main()
{
    int test, cases = 1;
    lint n;

    genSieve();

    scanf("%d", &test);

    while(test--){
        scanf("%lld", &n);
        printf("Case %d: %lld\n", cases++, numDiv(n) - 1);
    }

    return 0;
}
