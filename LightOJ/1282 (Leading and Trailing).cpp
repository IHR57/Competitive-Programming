#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#define MAX 100005
using namespace std;

typedef long long lint;

lint bigMod(lint a, lint b, lint m)
{
    if(b == 0)
        return 1;
    lint x = bigMod(a, b/2, m);
    x = (x * x) % m;

    if(b % 2 == 1){
        x = (x * a) % m;
    }

    return x;
}

int main()
{
    int test, cases = 1;
    lint a, b;

    scanf("%d", &test);

    while(test--){
        scanf("%lld %lld", &a, &b);
        double x, y;
        x = (double)(b * log10(a)) + 1e-12;
        //cout<<x<<endl;
        y = (floor)(pow((double)10, x - floor(x) + 2)) + 1e-12;       //first 3 digit of the number a^b
        //cout<<y<<endl;
        //lint firstThree = (lint) y;
        lint lastThree = bigMod(a, b, 1000);        //last three digit

        printf("Case %d: ", cases++);

        printf("%03lld ", lint(y));
        if(lastThree / 10 == 0){
            printf("00%lld\n", lastThree);
        }
        else if(lastThree / 100 == 0)
            printf("0%lld\n", lastThree);
        else
            printf("%lld\n", lastThree);
    }

    return 0;
}
