#include <iostream>
#include <cstdio>
using namespace std;

long GCD(long a, long b)
{
    long t;

    if(a==0)
        return b;
    else if(b==0)
        return a;
    else{
        while(b!=0){
            t=b;
            b=a%b;
            a=t;
        }
        return a;
    }
}

int main()
{
    long x, y, result;

    while(cin>>x>>y){
        result=GCD(x, y);
        if(result==1){
            printf("%10ld%10ld     Good Choice\n\n", x, y);
        }
        else
            printf("%10ld%10ld     Bad Choice\n\n", x, y);
    }

    return 0;
}
