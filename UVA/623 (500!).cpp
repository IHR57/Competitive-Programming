#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

char f[10000];  //maximum number of digits
char factorial[1010][10000];    //two dimensional character array

void multiply(int k)
{
    int i=0;
    int Cin=0, sum;
    int len=strlen(f);

    while(i<len){
        sum=Cin+(f[i]-'0')*k;
        f[i]=(sum%10)+'0';
        i++;
        Cin=sum/10;
    }
    while(Cin>0){
        f[i++]=(Cin%10+'0');
        Cin=Cin/10;
    }
    f[i]='\0';  //assign null at the end;
    for(int j=0; j<i; j++){
        factorial[k][j]=f[j];   //copying the digits in 2D array
    }
    factorial[k][i]='\0';
}

void fac()
{
    int k;

    strcpy(f, "1");     //initial length is 1

    for(k=2; k<=1000; k++){
        multiply(k);
    }
}

void print(int n)
{
    int i;
    int len=strlen(factorial[n]);

    for(i=len-1; i>=0; i--){    //print the digits in reverse order
        printf("%c", factorial[n][i]);
        //cout<<factorial[n][i];
    }
    cout<<endl;
}

int main()
{
    factorial[0][0]='1';    //0!=1
    factorial[1][0]='1';    //1!=1

    int n;

    fac();      //initializing the factorial

    while(cin>>n){
        cout<<n<<"!"<<endl;
        print(n);       //just print it
    }

    return 0;
}
