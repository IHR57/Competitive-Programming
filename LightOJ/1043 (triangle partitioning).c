#include <stdio.h>
#include <math.h>

int main()
{
    long long test, i;
    double a, b, c, Ratio, d, result;

    scanf("%lld", &test);

    for(i=0; i<test; i++){
        scanf("%lf %lf %lf %lf", &a, &b, &c, &Ratio);

        d=Ratio/(Ratio+1);
        result=a*sqrt(d);

        printf("Case %lld: %lf\n", i+1,  result);
    }

    return 0;
}

