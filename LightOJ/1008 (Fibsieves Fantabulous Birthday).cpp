#include <iostream>
#include <cstdio>
#include <math.h>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef long long int lint;

int main()
{
    int test, cases = 1;
    lint s, sqrtS,temp, value1, value2, square;

    scanf("%d", &test);

    while(test--){
        scanf("%lld", &s);

        sqrtS = ceil(sqrt((double)s));

        square = sqrtS * sqrtS;
        temp = (sqrtS - 1) * (sqrtS - 1);

        value1 = square - s;
        value2 = s - temp;

        printf("Case %d: ", cases++);
        if(sqrtS % 2 != 0){
            if(value1 < sqrtS){
                value1 = (square - value2) % sqrtS;
                if(value1 == 0)
                    value1 = sqrtS;
                printf("%lld %lld\n", value1, sqrtS);
            }
            else{
                value1 = square - (temp + value1);
                printf("%lld %lld\n", sqrtS, value1);
            }
        }
        else if(sqrtS % 2 == 0){
            if(value1 < sqrtS){
                value1 = (square - value2) % sqrtS;
                if(value1 == 0)
                    value1 = sqrtS;
                printf("%lld %lld\n", sqrtS, value1);
            }
            else{
                value1 = square - (temp + value1);
                printf("%lld %lld\n", value1, sqrtS);
            }
        }
       // printf("%lld\n", sqrtS);
    }

    return 0;
}
