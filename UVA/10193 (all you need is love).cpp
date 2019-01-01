#include <iostream>
#include <string.h>
#include <math.h>
#include <cstdio>
using namespace std;

int convertDecimal(char* str)
{
    int i, number=0, n;
    int len=strlen(str)-1;

    for(i=0; str[i]; i++){
        n=str[i]-48;
        number=number+(n*pow(2, len));
        len--;
    }
    return number;
}

int gcd(int a, int b)
{
    if(a%b==0)
        return b;
    return gcd(b, a%b);
}

int main()
{
    int test, j=1, value1, value2, findGCD;
    char str1[40], str2[40];

    cin>>test;

    while(test--){
        cin>>str1>>str2;
        value1=convertDecimal(str1);
        value2=convertDecimal(str2);

        findGCD=gcd(value1, value2);

        cout<<"Pair #"<<j++<<": ";
        if(findGCD==1)
            cout<<"Love is not all you need!"<<endl;
        else
            cout<<"All you need is love!"<<endl;

    }
}
