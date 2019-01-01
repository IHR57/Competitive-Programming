#include <iostream>
#include <math.h>
#define MAX 1005
using namespace std;

int primes[MAX];
int mark[MAX];
int nPrime;

void genSieve()
{
    primes[0]=1;
    primes[1]=2;
    nPrime=2;

    for(int i=4; i<=MAX; i+=2)
        mark[i]=1;

    int limit=sqrt(MAX);

    for(int i=3; i<=MAX; i++){
        if(mark[i]==0)
        {
            primes[nPrime++]=i;
            for(int j=i*i; j<MAX; j+=2*i){
                mark[j]=1;
            }
        }
    }
}

int main()
{
    genSieve();
    int N, C;

    while(cin>>N>>C){
        int count=0;
        int temp=N;

        N=N>1000?1000:N;

        for(int i=0; ; i++){
            if(primes[i]>N)
                break;
            count++;
        }

        int Min, Max;

        if(count%2==0){
            Min=count/2-C;
            Max=Min+2*C;
        }
        else{
            Min=count/2-C+1;
            Max=Min+2*C-1;
        }
        if(Min<0)
            Min=0;
        if(Max>count-1){
            Max=count;
        }

        cout<<temp<<" "<<C<<":";

        for(int i=Min; i<Max; i++){
            cout<<" "<<primes[i];
        }
        cout<<endl<<endl;
    }
}
