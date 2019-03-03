#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#define MAX 1005
using namespace std;

typedef long long ll;

int main()
{
    int test;
    ll n, k;

    scanf("%d", &test);

    while(test--){
        scanf("%lld %lld", &n, &k);
        ll sum = 0;
        ll sign = 1;
        while(n){
            sum += sign * n;
            n /= k;
            sign = -sign;
        }

        printf("%lld\n", sum);
    }

    return 0;
}
