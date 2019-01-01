#include <iostream>
#include <math.h>
using namespace std;

typedef long int lint;

lint primes[3165];
lint mark[31650];
lint counter;

bool isPrime(lint n)
{
    if(n==1)
        return false;
    if(n%2==0)
        return false;
    int sqrtN=sqrt(n+1);

    for(int i=3; i<=sqrtN; i+=2){
        if(n%i==0)
            return false;
    }

    return true;
}

void sieve()
{
    mark[1]=1;
    for(lint i=4; i<31650; i+=2){
        mark[i]=1;
    }

    counter=0;          //set counter equal zero
    primes[counter++]=2;        //2 is the only even prime

    lint limit=sqrt(31650);
    for(lint i=3; i<31650; i+=2){
        if(!mark[i]){
            primes[counter++]=i;
            if(i<=limit){
                for(lint j=i*i; j<31650; j+=i*2){
                    mark[j]=1;
                }
            }
        }
    }
}

lint EulerPhi(lint n)
{
    lint pf_index=0, pf=primes[pf_index], ans=n;

    while(pf*pf<=n){
        if(n%pf==0){
            ans-=ans/pf;
        }
        while(n%pf==0){
            n/=pf;
        }
        pf=primes[++pf_index];        //go to next prime
    }

    if(n!=1){       //if n is prime
        ans-=ans/n;
    }

    return ans;
}

int main()
{
    sieve();

    lint input, result;

    while(cin>>input){
        if(input==0)
            break;
        if(isPrime(input)==true){
            result=input-1;
        }
        else
            result=EulerPhi(input);
        cout<<result<<endl;
    }
    return 0;
}
