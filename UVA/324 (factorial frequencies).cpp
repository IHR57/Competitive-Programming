#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

char digit[1000];
char factorial[400][1000];

void multiply(int k)
{
    int sum, input, i;
    int len=strlen(digit);

    i=input=0;

    while(i<len){
        sum=input+(digit[i]-'0')*k;
        digit[i]=(sum%10)+'0';
        i++;
        input=sum/10;
    }

    while(input>0){
        digit[i++]=(input%10)+'0';
        input=input/10;
    }
    digit[i++]='\0';

    for(int j=0; j<i; j++){
        factorial[k][j]=digit[j];
    }
    factorial[k][i]='\0';
}

void init()
{
    strcpy(digit, "1");
    int k;

    for(k=2; k<=366; k++){
        multiply(k);
    }
}

void print(int k)
{
    factorial[0][0]='1';
    factorial[1][0]='1';

    int i;
    int len=strlen(factorial[k]);
    int one, two, three, four, five, six, seven, eight, nine, zero;
    zero=one=two=three=four=five=six=seven=eight=nine=0;

    for(i=len-1; i>=0; i--){
        switch(factorial[k][i])
        {
        case '0': zero++; break;
        case '1': one++; break;
        case '2': two++; break;
        case '3': three++; break;
        case '4': four++; break;
        case '5': five++; break;
        case '6': six++; break;
        case '7': seven++; break;
        case '8': eight++; break;
        case '9': nine++; break;
        }
    }
    printf("   (0)   %2d    (1)   %2d    (2)   %2d    (3)   %2d    (4)   %2d\n", zero, one, two, three, four);
    printf("   (5)   %2d    (6)   %2d    (7)   %2d    (8)   %2d    (9)   %2d\n", five, six, seven, eight, nine);
}

int main()
{
    init();
    int n;

    while(cin>>n && n!=0){
        cout<<n<<"! --"<<endl;
        print(n);
    }

    return 0;
}
