#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;

typedef long int lint;

int main()
{
    int test, cases = 1, index;
    lint b, value;
    char str[300];

    scanf("%d", &test);

    while(test--){
        scanf("%s %ld", str, &b);

        int len = strlen(str);

        if(str[0]=='-')
            index = 1;
        else
            index = 0;

        value = 0;

        for(int i=index; i<len; i++){
            value = value*10 + (str[i]-48);
            value = value%b;
        }

        if(!value)
            printf("Case %d: divisible\n", cases++);
        else
            printf("Case %d: not divisible\n", cases++);
    }

    return 0;
}
