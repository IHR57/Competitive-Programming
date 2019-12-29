//Problem ID: HackerRank - Tower Breakers, Again
//Programmer: IQBAL HOSSAIN     Description: Game Theory
//Date: 09/05/19
//Problem Link: https://www.hackerrank.com/challenges/tower-breakers-again-1/problem
#include <bits/stdc++.h>
#define MAX 505
using namespace std;

int mark[MAX], primes[MAX], counter = 0;

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

int primeCounter(int n)
{
    int idx = 0, pf = primes[idx], cnt = 0;
    while(pf * pf <= n){
        if(n % pf == 0){
            while(n % pf == 0){
                n /= pf;
                if(pf != 2)
                    cnt++;
            }
        }
        pf = primes[++idx];
    }
    if(n > 2)
        cnt++;

    return cnt;
}

int main()
{
    genSieve();
    int test, n, ans, m;

    scanf("%d",  &test);

    while(test--){
        scanf("%d", &n);
        ans = 0;
        for(int i = 0; i < n; i++){
            scanf("%d", &m);
            (m % 2) ? ans ^= primeCounter(m) : ans ^= (primeCounter(m) + 1);
        }
        (ans) ? printf("1\n") : printf("2\n");
    }

    return 0;
}
