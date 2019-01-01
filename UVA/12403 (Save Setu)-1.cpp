#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

int main()
{
    int test, operation, sum, cases = 1, donation;
    char str[100];


    scanf("%d", &operation);
    sum = 0;

    for(int i=0; i<operation; i++){
        scanf("%s", str);
        if(strcmp("donate", str)==0){
            scanf("%d", &donation);
            sum = sum+donation;
        }
        else if(strcmp("report", str)==0){
            printf("%d\n", sum);
        }
    }

    return 0;
}
