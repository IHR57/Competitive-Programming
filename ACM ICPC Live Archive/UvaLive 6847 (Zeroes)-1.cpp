#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#define MAX 30005
using namespace std;

typedef long long ll;

int main()
{
    ll l, r;

    while(scanf("%lld %lld", &l, &r) == 2){
        if(!l && !r)
            break;
        ll ans = (r / 5 - l / 5 + 1);
        printf("%lld\n", ans);
    }

    return 0;
}
