#include <iostream>
#include <cstdlib>
#include <math.h>
#define MAX 46400
using namespace std;

int primes[4800], counter;
int marks[46400];

void genSieve()
{
    int limit=sqrt(MAX);
    counter=0;
    marks[1]=1;
    for(int i=4; i<MAX; i+=2){
        marks[i]=1;
    }

    primes[counter++]=2;

    for(int i=3; i<MAX; i+=2){
        if(!marks[i]){
            primes[counter++]=i;
            if(i<=limit){
                for(int j=i*i; j<MAX; j+=2*i){
                    marks[j]=1;
                }
            }
        }
    }
}

int main()
{
    int n, factor_size, original;

    genSieve();             //generating primes
    while(cin>>n && n!=0){
        factor_size=0;
        int factor[100];

        if(n==-1)
            cout<<"-1 = -1"<<endl;
        else if(n==1)
            cout<<"1 = 1"<<endl;
        else{
            original=n;     //copy the n into original

            cout<<original<<" = ";
            if(n<1){
                n=fabs(n);      //if n is negative make it positive
                cout<<"-1 x ";
            }
            int sqrtN=sqrt(n+1);
            for(int i=0; primes[i]<=sqrtN; i++){        //using rules of prime factorization
                if(n%primes[i]==0){
                    while(n%primes[i]==0){
                        n/=primes[i];
                        factor[factor_size++]=primes[i];
                    }
                }
            }
            if(n>1){
                factor[factor_size++]=n;
            }

            for(int i=0; i<factor_size-1; i++){
                    cout<<factor[i]<<" x ";
            }
            cout<<factor[factor_size-1]<<endl;      //printing the last prime factor
        }
    }

    return 0;
}
