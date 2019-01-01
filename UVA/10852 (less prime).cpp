#include <iostream>
#include <math.h>
#include <cstdio>
using namespace std;

bool isPrime(int n)
{
    int sq=sqrt(n+1);
    if(n%2==0)
       return false;
    for(int i=3; i<=sq; i+=2){
        if(n%i==0)
            return false;
    }
    return true;
}

int main()
{
    int test, number, i, half, value;
    cin>>test;

    while(test--){
        cin>>number;
        half=number/2;
        for(i=half+1; i<number; i++){
            if(isPrime(i)==true){
                value=i;
                break;
            }
        }
        printf("%d\n", value);
    }

    return 0;
}
