#include <iostream>
#include <math.h>
#include <cstdio>
#define N 31650
using namespace std;

int mark[N];
int primes[N/10];
int counter;

void genSieve()
{
    mark[1]=0;
    counter=0;

    for(int i=4; i<N; i+=2){
        mark[i]=1;
    }

    primes[counter++]=2;
    int limit=sqrt(N);

    for(int i=3; i<N; i+=2){
        if(!mark[i]){
            primes[counter++]=i;
            if(i<=limit){
                for(int j=i*i; j<N; j+=i*2){
                    mark[j]=1;
                }
            }
        }
    }
}

int numDiv(int n)           //this function returns the number of divisor
{
    int pf_index=0, pf=primes[pf_index], result=1;

    while(pf*pf<=n){
        int count=0;
        while(n%pf==0){
            n/=pf;
            count++;
        }
        result*=(count+1);      //according to formula
        pf=primes[++pf_index];
    }

    if(n!=1){
        result*=2;
    }
    //cout<<result<<endl;
    return result;
}

int main()
{
    genSieve();
    int test, lower, upper, index, i;
    int div, Max;

    cin>>test;

    while(test--){
        scanf("%d %d", &lower, &upper);
        if(lower==0 && upper==1){       //special case;
            cout<<"Between "<<lower<<" and "<<upper<<", ";
            cout<<1<<" has a maximum of "<<1<<" divisors."<<endl;
            continue;
        }
        else if(lower==0 && upper!=0 && upper!=1){
            lower=2;
        }
        Max=0, index=0;
        for(i=lower; i<=upper; i++){
            div=numDiv(i);
            if(div>Max){
                index=i;        //save the number who has maximum divisor
                Max=div;
            }
        }

        cout<<"Between "<<lower<<" and "<<upper<<", ";
        cout<<index<<" has a maximum of "<<Max<<" divisors."<<endl;
    }

    return 0;
}
