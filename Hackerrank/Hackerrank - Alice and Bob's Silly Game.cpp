//Problem ID: HackerRank - Alice and Bob's Silly Game
//Programmer: IQBAL HOSSAIN     Description: Number/Game Theory
//Date: 04/05/19
//Problem Link: https://www.hackerrank.com/challenges/alice-and-bobs-silly-game/problem
#include <bits/stdc++.h>
#define MAX 100010
using namespace std;

int primes[MAX/10], mark[MAX], counter = 0;

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
int main()
{
    genSieve();
    int test, n, res;

    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);
        if(n == 1){
            printf("Bob\n");
            continue;
        }
        res = lower_bound(primes, primes + counter, n) - primes;
        if(binary_search(primes, primes + counter, n)){
            res++;
        }
        //cout<<res<<endl;
        (res % 2) ? printf("Alice\n") : printf("Bob\n");
    }

    return 0;
}
