#include <iostream>
#include <math.h>
#include <cstdio>
using namespace std;

typedef long long int lint;

int main()
{
    int test, flag, cases = 1;
    lint dashing_factor, value, d;

    scanf("%d", &test);

    while(test--){
        //flag = 0;
        scanf("%lld", &dashing_factor);

        if(dashing_factor%2!=0){
            printf("Case %d: Impossible\n", cases++);
            continue;
        }

        value = 0;

        for(int i=1; value<=dashing_factor; i++){
            value = pow(2, (double)i);

            if(dashing_factor%value == 0){
                d = dashing_factor/value;
                if(d%2!= 0){
                    printf("Case %d: %lld %lld\n", cases++, d, value);
                    continue;
                }
            }
        }

       // if(!flag){
        //    printf("Case %d: Impossible\n", cases++);
        //}

    }

    return 0;
}
