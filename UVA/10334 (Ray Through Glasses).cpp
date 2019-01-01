#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

const int length=1005;
char fib[length][5000];

char* bigSum(char* FibFirst, char* FibSecond);
void revStr(char* one);

int main()
{
    strcpy(fib[0], "0");
    strcpy(fib[1], "1");
    strcpy(fib[2], "1");

    for(int i=3; i<length; i++){
        strcpy(fib[i], bigSum(fib[i-1], fib[i-2]));
    }

    int input;
    while(cin>>input){
        printf("%s\n", fib[input+2]);
    }

    return 0;

}

char* bigSum(char* FibFirst, char* FibSecond)
{
    char *FibSum;
    FibSum=new char[length];
    int length1, length2;
    int first, second, sum, carry=0, i=0;

    length1=strlen(FibFirst)-1;
    length2=strlen(FibSecond)-1;

    //FibSum[0]='\0';

    while(length1>=0 || length2>=0){
        first=FibFirst[length1]-48;
        second=FibSecond[length2]-48;

        if(length1<0)
            first=0;
        if(length2<0)
            second=0;

        sum=first+second+carry;

        if(sum>9)
            carry=1;
        else
            carry=0;
        FibSum[i]=(sum%10)+48;
        ++i;
        --length1; --length2;
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

void revStr(char *one)
{
    char temp[length];
    int len=strlen(one)-1;
    int j=0;
    for(int i=len; i>=0; i--){
        temp[j]=one[i];
        j++;
    }
    temp[j]='\0';
    strcpy(one, temp);
}

