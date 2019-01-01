#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;
typedef long long int lint;

int mark[1001000];
int primes[100100];
lint n;
int counter;

void genSieve()
{
    counter=0;
    mark[1]=1;
    for(int i=4; i<=1000001; i+=2)
        mark[i]=1;

    int limit=sqrt(10000001);

    primes[counter++]=2;

    for(int i=3; i<=1000001; i+=2){
        if(!mark[i]){
            primes[counter++]=i;
            if(i<=limit){
                for(int j=i*i; j<=1000001; j+=2*i)
                    mark[j]=1;
            }
        }
    }
}

int main()
{
    genSieve();

    while(scanf("%lld", &n)==1){
        if(n<0)
            break;
        lint sqrtN=sqrt(n+1);
        for(int i=0; i<counter; i++){
            while(n%primes[i]==0){
                printf("    %d\n", primes[i]);
                n/=primes[i];
            }
        }
        if(n>1)
            printf("    %lld\n", n);
        printf("\n");
    }

    return 0;
}
