#include <iostream>
#include <cstdio>
#include <math.h>
#include <string.h>
using namespace std;

int main()
{
    char str[500], ch;
    int sum, m=131071, base;

    while(cin>>ch){
        sum=0, base=2;
        sum+=ch-48;
        while(cin>>ch){
            if(ch=='#') break;
            sum = sum*base;
            sum = sum+ch-48;
            sum = sum%m;        //convert binary to decimal digit by digit and mod the sum
        }

        if(sum==0)      //if sum equal zero then the number is divisible by 131071
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
