#include <iostream>
#include <math.h>
#define MAX 1000005
using namespace std;

int primes[200];
int result[MAX];
int mark[1010];
int Counter;

void genSieve()         //generating prime upto 1000
{
    mark[1]=1;
    Counter=0;

    for(int i=4; i<1010; i+=2){
        mark[i]=1;
    }

    primes[Counter++]=2;

    int limit=sqrt(1010);

    for(int i=3; i<1010; i+=2){
        if(!mark[i]){
            primes[Counter++]=i;
            if(i<=limit){
                for(int j=i*i; j<1010; j+=i*2){
                    mark[j]=1;
                }
            }
        }
    }
}

int CountFactor(int n)          //this function counts the total prime factor of a number
{
    int pf_index=0, pf=primes[pf_index], Count =0;

    while(pf*pf<=n){
        while(n%pf==0){
            n/=pf;
            Count++;
        }
        pf=primes[++pf_index];
    }

    if(n!=1)
        Count++;

    return Count;
}

int main()
{
    genSieve();         //generating primes

    result[1]=0;            //set result[1] = 0
    for(int i=2; i<=MAX; i++){
        result[i]=result[i-1]+CountFactor(i);
    }

    int input;

    while(cin>>input){
        cout<<result[input]<<endl;
    }

    return 0;
}
