#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string.h>
#define MAX 1010
using namespace std;

typedef long long lint;

int primes[400], counter = 0;
bool mark[MAX];
int mu[1000005], M[1000005];

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

void differentPrimeFactor()
{
    int pf, idx, flag, factorCount, temp, count;
    mu[1] = 1, M[1] = 1;

    for(int i = 2; i < 1000001; i++){
        flag = 1, factorCount = 0, temp = i;
        idx = 0, pf = primes[idx];
        while(pf * pf <= temp){
            count = 0;
            while(temp % pf == 0){
                temp /= pf;
                count++;
                if(count == 1){
                    factorCount++;
                }
                if(count >= 2){
                    flag = 0;
                }
            }
            pf = primes[++idx];
        }
        if(temp != 1)   factorCount++;
        //cout<<factorCount<<endl;
        if(!flag)
            mu[i] = 0;
        else if(flag == 1 && factorCount % 2 == 0){
            mu[i] = 1;
        }
        else if(flag == 1 && factorCount % 2 != 0)
            mu[i] = -1;
        M[i] = M[i - 1] + mu[i];
    }
}

int main()
{
    int n;

    genSieve();
    differentPrimeFactor();

    while(scanf("%d", &n) == 1){
        if(!n)  break;
        printf("%8d%8d%8d\n", n, mu[n], M[n]);
    }

    return 0;
}
