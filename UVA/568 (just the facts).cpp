#include <stdio.h>
#include <string.h>

char f[50000];  //maximum number of digit
char factorial[10000][50000];    //multidimensional character array

void multiply(int k)
{
    int Cin, sum, i;
    int len=strlen(f);  //at first length equal to 1
    Cin=0;
    i=0;
    while(i<len){
        sum=Cin+(f[i]-'0')*k;
        f[i]=(sum%10)+'0';
        i++;
        Cin=sum/10;
    }
    while(Cin>0){
        f[i++]=(Cin%10)+'0';
        Cin/=10;
    }
    f[i]='\0';
    for(int j=0; j<i; j++){
        factorial[k][j]=f[j];
    }
    factorial[k][i]='\0';
}

void fac()
{
    int k;
    strcpy(f, "1");

    for(k=2; k<10000; k++){
        //int len=strlen(f);
        //printf("%d\n", len);
        multiply(k);
    }
}

int print(int n)
{
    int i, value;
    int len=strlen(factorial[n]);   //number of digit in n!

    for(i=0; i<len; i++){    //print it reverse
        if(factorial[n][i]!='0'){
            value=factorial[n][i]-'0';
            break;
        }
    }
    return value;
}

int main()
{
    int n, non_zero;
    factorial[0][0]='1';    //0!=1;
    factorial[1][0]='1';    //1!=1;

    fac();  //initializing all factorial between 1 to 1000

    while(scanf("%d", &n)==1){
        non_zero=print(n);
        printf("%5d -> %d\n", n, non_zero);
    }

    return 0;
}


