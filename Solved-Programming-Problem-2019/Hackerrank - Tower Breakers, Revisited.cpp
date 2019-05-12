//Problem ID: HackerRank - Tower Breakers, Revisited
//Programmer: IQBAL HOSSAIN     Description: Game Theory (Grundy Number)
//Date: 09/05/19
//Problem Link: https://www.hackerrank.com/challenges/tower-breakers-revisited-1/problem
#include <bits/stdc++.h>
#define MAX 1020
using namespace std;

int primes[MAX], mark[MAX], counter = 0;

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
                cnt++;
            }
        }
        pf = primes[++idx];
    }

    if(n != 1)
        cnt++;

    return cnt;
}

int main()
{
    genSieve();
    int test, n, m, ans;

    scanf("%d",  &test);

    while(test--){
        scanf("%d",  &n);
        ans = 0;
        for(int i = 0; i < n; i++){
            scanf("%d", &m);
            int res = primeCounter(m);
            ans ^= res;
        }
        (ans) ? printf("1\n") : printf("2\n");
    }

    return 0;
}
