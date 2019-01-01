#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <algorithm>
#define MAX 90000000
using namespace std;

int status[MAX / 32];
int primes[5300000], counter = 1;

bool check(int n, int pos)
{
    return (bool) (n & (1 << pos));
}

int Set(int n, int pos)
{
    return n = n | ( 1 << pos);
}

void genSieve()
{
    int sqrtN = sqrt(MAX + 1);

    for(int i = 3; i <= sqrtN; i += 2){
        if(check(status[i / 32], i % 32) == 0){
            for(int j = i * i; j < MAX; j += i * 2){
                status[j / 32] = Set(status[j / 32], j % 32);       //mark as not prime
            }
        }
    }

    int count = 0;

    primes[counter++] = 2;

    for(int i = 3; i < MAX; i += 2){
        if(check(status[i / 32], i % 32) == 0){
            primes[counter++] = i;
        }
    }
}

int main()
{
    genSieve();

    int query, n;

    scanf("%d", &query);

    //cout<<counter<<endl;

    while(query--){
        scanf("%d", &n);
        printf("%d\n", primes[n]);
    }

    return 0;
}
