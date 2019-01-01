#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

int main()
{
    int n;

    scanf("%d", &n);

    for(int i = 0; i < n / 2; i++){
        if(i % 2 == 0)
            printf("bb");
        else
            printf("aa");
    }

    if(n % 2 != 0){
        if((n / 2) % 2 == 0){
            printf("b");
        }
        else
            printf("a");
    }

    printf("\n");

    return 0;
}
