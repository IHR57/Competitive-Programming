#include <iostream>
#include <cstdio>
#include <math.h>
#include <algorithm>
#define MAX 100005
using namespace std;

int primes[MAX/10];
int mark[MAX];

void genSieve()
{
    int limit = sqrt(MAX);

    mark[1] = 1;        //as 1 is not prime

    for(int i = 4; i < MAX; i += 2){
        mark[i] = 1;
    }

    int counter = 0;

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

int main()
{
    int n, k;

    genSieve();

    cin>>n;

    int j = 0;
    if(n <= 2)
        k = 1;
    else
        k = 2;

    cout<<k<<endl;

    for(int i = 2; i <= n+1; i++){
        if(i == primes[j]){
            j++;
            cout<<"1 ";
        }
        else
            cout<<"2 ";
    }

    cout<<endl;

    return 0;
}
