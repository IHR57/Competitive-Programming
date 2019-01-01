#include <iostream>
#include <algorithm>
#include <cstdio>
#include <math.h>
using namespace std;

typedef long long int lint;

lint divisor[1000005];

int main()
{
    lint P, L, Q;
    int test, cases = 1;

    scanf("%d", &test);
    while(test--){
        scanf("%lld %lld", &P, &L);
        Q = (P - L);

        printf("Case %d:", cases++);

        //special Case
        if( L >= Q){
            printf(" impossible\n");
            continue;
        }

        int sqrtQ = (int) sqrt(Q) + 1;

        int j = 0;
        for(int i = 1; i <= sqrt(Q); i++){
            if(Q % i == 0 && i*i != Q){
                divisor[j++] = i;
                divisor[j++] = Q / i;
            }

            if(Q % i == 0 && i*i == Q){
                divisor[j++] = i;
            }
        }

        int len = j;

        sort(divisor, divisor + len);

        for(int i = 0; i < len; i++){
            if(divisor[i] > L)
                printf("% lld", divisor[i]);
        }
        printf("\n");
    }

    return 0;
}
