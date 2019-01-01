#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;

int main()
{
    int m, b, y;
    long long int s1, s2, result = 0, sum, x;

    scanf("%d %d", &m, &b);

    for(y = b; y >= 0; y--){
        x = m * (b - y);        //given y = -(x / m) + b;  so x = m * (b - y)
        sum = 0;
        s1 = (x + 1) * ((y * (y + 1)) / 2);
        s2 = (y + 1) * ((x * (x + 1)) / 2);
        sum += (s1 + s2);
        result = max(result, sum);
    }

    printf("%lld\n", result);

    return 0;
}
