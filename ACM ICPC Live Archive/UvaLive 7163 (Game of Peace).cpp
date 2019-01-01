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
    ll fib[80];

    fib[0] = 1, fib[1] = 1;
    for(int i = 2; i <= 71; i++)
        fib[i] = fib[i-1] + fib[i-2];

    int test, caseno = 1;
    ll x, n, y, m;

    scanf("%d", &test);

    while(test--){
        scanf("%lld %lld %lld %lld", &x, &n, &y, &m);
        ll temp1, temp2;
        if(n == 0){
            temp1 = x + y;
            temp2 = 0;
        }
        else{
            temp1 = (x * fib[n]);
            temp2 = (x * fib[n-1]);
            temp1 += y;
        }
        ll ans = __gcd(temp1, temp2);

        printf("Case %d: %lld\n", caseno++, ans);
    }

    return 0;
}
