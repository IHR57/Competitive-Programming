#include <bits/stdc++.h>
#define MAX 120
using namespace std;

int primes[40];
int mark[MAX], counter = 0, index[120];

void genSieve()         //generating prime
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

void factorize(int n)
{
    for(int i = n; i >= 2; i--){        //factorize a factorial
        int sqrtN = sqrt(i);
        int temp = i;
        for(int j = 0; primes[j] <= sqrtN; j++){
            if(temp % primes[j] == 0){
                while(temp % primes[j] == 0){
                    temp = temp / primes[j];
                    index[primes[j]]++;     //we have to print how many times a prime occurs
                }
            }
        }
        if(temp > 1)
            index[temp]++;
    }
}

int main()
{
    int test, cases = 1, n;

    genSieve();

    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);        //we have to factorize n!

        for(int i = 0; i < 120; i++)
            index[i] = 0;

        factorize(n);

        printf("Case %d: ", cases++);
        printf("%d = %d (%d)", n, primes[0], index[primes[0]]);
        for(int i = 1; i <= 30; i++){
            if(index[primes[i]] != 0){
                printf(" * %d (%d)", primes[i], index[primes[i]]);
            }
        }
        printf("\n");
    }

    return 0;
}
