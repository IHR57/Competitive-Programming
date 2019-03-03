#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

ll floorSqrt(ll n)
{
    if(n == 0 || n == 1)
        return n;
    int i = 1, result = 1;
    while(result <= n){
        i++;
        result = i * i;
    }

    return i - 1;
}

int main()
{
    ll test, caseno = 1, n, last, first;
    ll csod;

    scanf("%lld", &test);

    while(test--){
        scanf("%lld", &n);
        csod = 0;

        ll sqrtN = floorSqrt(n);
        last = n / 2;

        ll div = 3, k = 1;
        while(last > sqrtN){
            ll temp = n / div;
            first = temp + 1;
            ll term = last - first + 1;
            ll sum = (term * ((2 * first) + (term - 1))) / 2;
            csod += (sum * k);
            div++, k++;
            last = temp;
        }
        for(int i = 2; i <= sqrtN; i++){
            csod += (i * (n / i - 1));
        }

        printf("Case %lld: %lld\n", caseno++, csod);
    }

    return 0;
}
