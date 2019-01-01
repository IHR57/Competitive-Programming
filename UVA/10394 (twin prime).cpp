#include <iostream>
#include <math.h>
#include <string>
using namespace std;

typedef long int lint;

char sieve[20000000];
lint primes[100002];
void genSieve();

int main()
{
    genSieve();
    lint  s, i, j;

    while(cin>>s){

        cout<<"("<<primes[s-1]<<", "<<primes[s-1]+2<<")"<<endl;
    }

    return 0;
}

void genSieve()
{
    lint i, j, sq;

    sq=sqrt((double)20000000);

    sieve[0]=sieve[1]=1;
    for(i=2; i<=sq; i++){
        if(!sieve[i]){
            for(j=i+i; j<20000000; j+=i){
                sieve[j]=1;
            }
        }
    }

    j=0;
    //we don't need to take all primes number
    for(i=2; i<20000000; i++){
        if(!sieve[i] && !sieve[i+2]){   //we only took the first number of twin primes in the primes
            primes[j++]=i;
        }
        if(j==100001)   //if number of twin primes greater than 100000
            break;
    }

}
