#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <cstring>
#define MAX 100005
using namespace std;

typedef long long ll;

int n;
unsigned long long seed;

long double gen()
{
    static const long double Z = (long double) 1.0 / (1LL<<32);
    seed >>= 16;
    seed &= (1ULL <<32) - 1;
    seed *= seed;
    return seed * Z;
}

int main()
{
    int test, caseno = 1;

    scanf("%d", &test);

    while(test--){
        scanf("%d %llu", &n, &seed);
        long double sumx = 0, sumxx = 0, m, ans, x;
        for(int i = 0; i < n; i++){
            x = gen();
            sumx += x;
            sumxx += (x * x);
        }
        m = sumx / n;
        ans = (sumxx - 2 * sumx * m) / n + (m * m);
        ans = sqrt(ans);
        printf("Case #%d: %0.5lf\n", caseno++, (double)ans);
    }

    return 0;
}
