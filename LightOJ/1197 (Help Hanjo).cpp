#include <iostream>
#include <math.h>
#include <cstdio>
using namespace std;

typedef long int lint;

lint sieve(lint a, lint b)
{
    lint i, j, d;
    d=b-a+1;

    bool *flag=new bool[d];

    for(i=0; i<d; i++){
        flag[i]=true;
    }

    for(i=(a%2!=0); i<d; i+=2)
        flag[i]=false;
    //sieve by prime factor starting from 3 till sqrt(b);

    for(i=3; i<=sqrt(b); i+=2){
        if(i>a && !flag[i-a])
            continue;
        j=a/i*i;
        if(j<a)
            j+=i;
        if(j==i)
            j+=i;

        j-=a;
        for(; j<d; j+=i)
            flag[j]=false;
    }

    if(a<=1)
        flag[1-a]=false;
    if(a<=2)
        flag[2-a]=true;

    int k=0;
    for(i=0; i<d; i++){
        if(flag[i])
            k++;
    }

    return k;
}

int main()
{
    lint x, y, value, cases=1;
    int test;

    scanf("%d", &test);

    while(test--){
        scanf("%ld %ld", &x, &y);
        value = sieve(x, y);
        printf("Case %d: %ld\n", cases++, value);
    }

    return 0;
}

