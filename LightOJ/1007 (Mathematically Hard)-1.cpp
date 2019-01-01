#include <iostream>
#include <cstdio>
#define MAX 5000006
using namespace std;

typedef unsigned long long int lint;

lint phi[MAX];
int mark[MAX];

void sievePhi()     //this function generates phi from 1 to MAX
{
    int i, j;

    for(i=1; i<MAX; i++){
        phi[i]=i;
    }

    phi[1]=1;
    mark[1]=1;

    for(i=2; i<MAX; i++){
        if(!mark[i]){
            for(j=i; j<MAX; j+=i){
                mark[j]=1;
                phi[j]=phi[j] / i * (i-1);      //phi[j] will be divisible by i
            }
        }
    }

    for(int i=2; i<MAX; i++){       //dynamic programming
        phi[i]*=phi[i];
        phi[i]+=phi[i-1];
    }
}

int main()
{
    sievePhi();

    int a, b;
    int cases=1, test;

    scanf("%d", &test);

    while(test--){
        scanf("%d %dd", &a, &b);

        printf("Case %d: %llu\n", cases++, phi[b]-phi[a-1]);
    }

    return 0;
}
