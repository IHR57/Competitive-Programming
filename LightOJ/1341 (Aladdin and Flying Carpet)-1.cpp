#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string.h>
#define MAX 1000010
using namespace std;

typedef long long lint;

int primes[80000], counter = 0;
bool mark[MAX];

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
                for(int j = i * i; j < MAX; j += i * 2){
                    mark[j] = 1;
                }
            }
        }
    }
}

int numberofDivisor(lint n)     //return number of divisor / 2 of a given number
{
    int idx = 0,  ans = 1;
    lint pf = primes[idx];

    while(pf * pf <= n){
        int count = 0;
        while(n % pf == 0){
            n /= pf;
            count++;
        }
        ans *= (count + 1);
        pf = primes[++idx];
    }

    if(n != 1){
        ans *= 2;
    }

    return ans / 2;     //we need only first half number of divisor
}

int main()
{
    genSieve();

	int test, cases = 1;
	lint a, b;

	scanf("%d", &test);

	while(test--){
        scanf("%lld %lld", &a, &b);
        if(sqrt(a) <= b)
            printf("Case %d: 0\n", cases++);
        else{
            int count = 0;
            for(int i = 1; i < b; i++){
                if(a % i == 0)
                    count++;
            }
            printf("Case %d: %d\n", cases++, numberofDivisor(a) - count);
        }
	}

	return 0;
}
