#include <iostream>
#include <algorithm>
#include <cstdio>
#include <math.h>
using namespace std;

typedef long int lint;

int main()
{
    lint R, C, Q, divisor[500];
    int test, cases = 1;

    scanf("%d", &test);
    while(test--){
        scanf("%ld %ld", &C, &R);
        Q = (C - R);

        printf("Case #%d:", cases++);

        //special Case
        /*if( R >= Q){
            printf("\n");
            continue;
        }*/

        //special case
        if(R == C){
            printf(" 0\n");
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
            if(divisor[i] > R)
                cout<<" "<<divisor[i];
        }
        cout<<endl;
    }

    return 0;
}
