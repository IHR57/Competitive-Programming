#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#define MAX 100005
using namespace std;

typedef long long lint;

lint bigMod(lint a, lint b, lint m)
{
    if(b == 0)
        return 1;
    lint x = bigMod(a, b / 2, m);
    x = (x * x) % m;
    if(b % 2 == 1){
        x = (x * a) % m;
    }

    return x;
}

int main()
{
    int test;
    lint a, b, n;

    scanf("%d", &test);

    while(test--){
        scanf("%lld %lld %lld", &a, &b, &n);
        lint result = bigMod(a, b, n);
        printf("%lld\n", result);
    }

    return 0;
}
