#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long lint;

lint x, y, GCD;

/*lint greatestCommon(lint a, lint b)     //return the greatest common divisor
{
    if(a % b == 0)
        return b;
    return greatestCommon(b, a % b);
}*/

void extendedEuclid(lint a, lint b)
{
    if(b == 0){
        x = 1;  y = 0;
        GCD = a;
        return;
    }

    extendedEuclid(b, a % b);       //similar to
    x = x - (a / b) * y;
    swap(x, y);
}

int main()
{
    int test;
    lint a, b, a1, b1;

    scanf("%d", &test);

    while(test--){
        scanf("%lld %lld", &a, &b);
        a1 = (a / b);        //floor
        b1 = (lint) ceil(a / (double) b);
        //cout<<a<<" "<<b<<endl;

        //GCD = greatestCommon(a, b);
        extendedEuclid(a1, b1);           //calling extended euclid function

        lint n = a / GCD;

        printf("%lld %lld\n", x * n, y * n);
    }

    return 0;
}
