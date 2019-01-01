#include <iostream>
#include <cstdio>

typedef long int lint;

int main()
{
    int test, cases = 1;
    lint a, b, res1, res2, result, temp;

    scanf("%d", &test);

    while(test--){
        scanf("%ld %ld", &a, &b);

        if(a > b){
            temp = a;
            a = b;
            b = temp;
        }

        if(b % 3 == 2){
            res1 = 2 * (b / 3) + 1;
        }
        else
            res1 = 2 * (b / 3);

        a = a - 1;

        if(a % 3 == 2)
            res2 = 2 * (a / 3) + 1;
        else
            res2 = 2 * (a / 3);

        result = res1 - res2;

        printf("Case %d: %ld\n", cases, result);
    }

    return 0;
}
