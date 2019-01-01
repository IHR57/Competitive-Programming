#include <stdio.h>
#include <math.h>

double digit[1000005];
int i;

int main()
{

    long int test, number, base, cases = 1;

    for(i = 1; i < 1000005; i++){
        digit[i] = log10(i) + digit[i-1];       //memorization technique
    }

    scanf("%d", &test);

    while(test--){
        scanf("%ld %ld", &number, &base);
        printf("Case %ld: %ld\n", cases++, (long)(digit[number]/(digit[base] - digit[base-1])) + 1);
    }

    return 0;
}

