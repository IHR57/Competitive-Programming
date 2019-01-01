#include <iostream>
#include <math.h>
#include <cstdio>
using namespace std;

int mark[110];
int primes[50];
int k;

void genSieve()             //generating primes number between 2 to 110;
{
    mark[0]=mark[1]=1;
    k=0;

    for(int i=4; i<110; i+=2){
        mark[i]=1;
    }

    primes[k++]=2;

    int limit=sqrt(110);

    for(int i=3; i<110; i+=2){
        if(!mark[i]){
            primes[k++]=i;
            if(i<=limit){
                for(int j=i*i; j<110; j+=i*2){
                    mark[j]=1;
                }
            }
        }
    }
}

int main()
{
    genSieve();
    int n, counter[110], count, temp;

    while(cin>>n && n!=0){
        for(int i=0; i<101; i++){
            counter[i]=0;           //initially set all counter to zero
        }
        for(int i=n; i>1; i--){
            temp=i;
            if(!mark[temp]){        //if it is prime number not need to factorize it
                counter[temp]+=1;       //increment the counter
                continue;
            }
            for(int j=0; j<k; ){            //if not prime number
                if(temp%primes[j]==0){
                    counter[primes[j]]++;
                    temp=temp/primes[j];
                    continue;
                }
                j++;
            }
        }
        count=1;
        printf("%3d! =", n);
        for(int i=0; i<101; i++){
            if(counter[i]!=0 && count!=16){
                printf("%3d", counter[i]);          //we have to print 15 number in one line
                count++;
            }
            else if(counter[i]!=0 && count==16){        //if number greater than 15
                printf("\n%9d", counter[i]);
                count=1;            //set count equal 1
            }
        }
        cout<<endl;
    }

    return 0;
}
