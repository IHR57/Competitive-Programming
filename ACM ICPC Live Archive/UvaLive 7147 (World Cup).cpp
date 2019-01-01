#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#define MAX 100005
using namespace std;

typedef long long ll;

int main()
{
    ll n, m, a, b, c;
    int test, caseno = 1;

    scanf("%d",  &test);
    while(test--){
        scanf("%lld %lld", &n, &m);
        scanf("%lld %lld %lld",  &a, &b, &c);
        if(a < c)
            swap(a, c);
        ll result1 = 0, result2 = 0;
        result1 += (n - m - 1) * max(a, b);
        result1 += (m / 2) * max(a + c, 2 * b);
        if(m % 2 != 0)
            result1 += max(b, c);

        result2 += (m - 1) * min(b, c);
        result2 += (n - m) / 2 * min(a + c, 2 * b);
        if((n - m) % 2 != 0){
            result2 += min(a, b);
        }

        printf("Case #%d: %lld %lld\n", caseno++, result1, result2);
    }

    return 0;
}
