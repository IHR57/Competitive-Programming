#include <iostream>
#include <algorithm>
#include <cstdio>
#include <math.h>
#include <string.h>
using namespace std;

typedef long int lint;

int main()
{
    int repeated, cases=1, temp[50], non_repeated;
    char str[100];
    int sum, value, denominator, numerator, GCD;

    temp[0]=1;
    for(int i=1; i<10; i++){
        temp[i]=temp[i-1]*10;       //10 100 1000 10000 100000 ......
    }
    while(cin>>repeated){
        if(repeated==-1)
            break;
        denominator=numerator=0;
        cin>>str;
        int len=strlen(str);

        for(int i=2; i<len; i++){
            denominator=denominator*10+str[i]-48;   //converting the value after decimal into integer
        }

        if(repeated!=0){
            denominator=denominator-denominator/temp[repeated];
            numerator=temp[len-2]-temp[len-repeated-2];
        }
        else
            numerator=temp[len-2];

        GCD=__gcd(denominator, numerator);     //finding GCD

        cout<<"Case "<<cases++<<": "<<denominator/GCD<<"/"<<numerator/GCD<<endl;
    }

    return 0;
}
