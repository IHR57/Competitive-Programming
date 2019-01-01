#include <iostream>
#include <cstdio>
using namespace std;

typedef unsigned long long int lint;

lint ncr(lint n, lint r)
{
    lint prod=1;
    lint k=n;

    for(int i=1; i<=r; i++){
        prod=(prod*k--)/i;
    }

    return prod;
}

int main()
{
    lint n, r, result, value;

    while(cin>>n>>r){
        if(n==0 && r==0)
            break;
        value=r;
        if(n-r<value)
            value=n-r;
        result=ncr(n, value);

        printf("%llu things taken %llu at a time is %llu exactly.\n", n, r, result);
    }

    return 0;
}
