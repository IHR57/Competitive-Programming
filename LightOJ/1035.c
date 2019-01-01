#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 120

int primes[40];
int mark[MAX], counter = 0, Index[MAX];

void genSieve()         //generating prime
{
    int limit = sqrt(MAX + 1);
    int i, j;

    mark[1] = 1;

    for(i = 4; i < MAX; i += 2)
        mark[i] = 1;

    primes[counter++] = 2;

    for(i = 3; i < MAX; i += 2){
        if(!mark[i]){
            primes[counter++] = i;
            if(i <= limit){
                for(j = i * i; j < MAX; j += i * 2){
                    mark[j] = 1;
                }
            }
        }
    }
}

void factorize(int n)
{
    int sqrtN, temp, i, j;

    for(i = n; i >= 2; i--){        //factorize a factorial
        sqrtN = sqrt(i);
        temp = i;
        for(j = 0; primes[j] <= sqrtN; j++){
            if(temp % primes[j] == 0){
                while(temp % primes[j] == 0){
                    temp = temp / primes[j];
                    Index[primes[j]]++;     //we have to print how many times a prime occurs
                }
            }
        }
        if(temp > 1)
            Index[temp]++;
    }
}

int main()
{
    int test, cases = 1, n, i, j;

    genSieve();

    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);        //we have to factorize n!

        for(i = 0; i < 120; i++)
            Index[i] = 0;

        factorize(n);

        printf("Case %d: ", cases++);
        printf("%d = %d (%d)", n, primes[0], Index[primes[0]]);
        for(i = 1; i <= 30; i++){
            if(Index[primes[i]] != 0){
                printf(" * %d (%d)", primes[i], Index[primes[i]]);
            }
        }
        printf("\n");
    }

    return 0;
}

