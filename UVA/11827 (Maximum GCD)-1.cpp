#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <string.h>
using namespace std;

int GCD(int x, int y)       //this function returns the GCD of two integer
{
    int r;

    while(y!=0){
        r=x%y;
        x=y;
        y=r;
    }

    return x;
}

int main()
{
    char inputStr[500], *tempStr;
    int value[200], test, Max, temp;

    scanf("%d", &test);
    getchar();

    while(test--){
        gets(inputStr);     //take input as string
        int i=0;
        tempStr=strtok(inputStr, " ");
        //value[i++]=atoi(tempStr);

        while(tempStr!=NULL){
            value[i++]=atoi(tempStr);       //take the value into an array
            tempStr=strtok(NULL, " ");
        }
        int len=i;
        Max=0;

        for(int i=0; i<len-1; i++){     //finding GCD between two element and comparing with Maximum
            for(int j=i+1; j<len; j++){
                temp=GCD(value[i], value[j]);
                if(temp>Max){
                    Max=temp;
                }
            }
        }

        printf("%d\n", Max);
    }

    return 0;
}
