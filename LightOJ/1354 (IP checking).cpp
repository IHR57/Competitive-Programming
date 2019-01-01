#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
using namespace std;

//this function takes string as an argument and convert it to integer number in base 10
int  convertBase10(char *str)
{
    int n, len, number=0;

    len=strlen(str);
    for(int i=0; str[i]; i++){
        n=str[i]-48;
        number=number+(n*pow(2, len-1));
        len--;
    }

    return number;
}

int main()
{
    int test, a, b, c, d, len, j, k;
    int value1, value2, value3, value4;

    cin>>test;

    for(int i=1; i<=test; i++){

        char bin1[100], bin2[100], bin3[100], bin4[100], text[100];
        scanf("%d.%d.%d.%d", &a, &b, &c, &d);
        scanf("%s", &text);

        int len=strlen(text);
        for(j=0; j<len/4; j++){     //takes first 8 character into bin1
            bin1[j]=text[j];
        }
        bin1[j]='\0';

        value1=convertBase10(bin1);     //calling the function to convert

        for(j=9, k=0; j<=16; j++, k++){
            bin2[k]=text[j];
        }
        bin2[k]='\0';

        value2=convertBase10(bin2);

        for(j=18, k=0; j<=25; j++, k++){
            bin3[k]=text[j];
        }
        bin3[k]='\0';

        value3=convertBase10(bin3);

        for(j=27, k=0; j<=35; j++, k++){
            bin4[k]=text[j];
        }
        bin4[k]='\0';

        value4=convertBase10(bin4);

        //printf("%d %d %d %d", value1, value2, value3, value4);

        if(value1==a && value2==b && value3==c && value4==d)
            cout<<"Case "<<i<<": "<<"Yes"<<endl;
        else
            cout<<"Case "<<i<<": "<<"No"<<endl;
    }

    return 0;
}
