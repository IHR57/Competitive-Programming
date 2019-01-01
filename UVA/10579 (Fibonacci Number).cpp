#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

const int length=5001;
char fib[length][length];

char *bigSum(char* FibFirst, char* FibSecond);
void revStr(char* one);

int main()
{
    strcpy(fib[0], "0");
    strcpy(fib[1], "1");
    strcpy(fib[2], "1");

    int input;

    for(int i=3; i<length; i++){
        strcpy(fib[i], bigSum(fib[i-1], fib[i-2]));
    }

    while(cin>>input){
        printf("%s\n", fib[input]);
        //printf("%d\n", strlen(fib[input]));
    }

    return 0;
}

char* bigSum(char* FibFirst, char* FibSecond)
{
    char* FibSum;
    FibSum=new char[length];

    int len1=strlen(FibFirst)-1;
    int len2=strlen(FibSecond)-1;
    int first, second, sum, carry=0, i=0;

    FibSum[0]='\0';

    while(len1>=0 || len2>=0){
        first=FibFirst[len1]-48;
        second=FibSecond[len2]-48;
        if(len1<0)  first=0;
        if(len2<0)  second=0;

        sum=first+second+carry;

        if(sum>9)
            carry=1;
        else
            carry=0;
        FibSum[i]=(sum%10)+48;
        ++i;
        --len1; --len2;
    }
    if(carry>0){
        FibSum[i]=carry+48;
        FibSum[++i]='\0';
    }
    else
        FibSum[i]='\0';

    revStr(FibSum);

    return FibSum;
}

void revStr(char* one)
{
    char temp[length];
    int len=strlen(one);
    int i=0, j;
    for(j=len-1; j>=0; j--){
        temp[i]=one[j];
        ++i;
    }
    temp[i]='\0';
    strcpy(one, temp);
}
