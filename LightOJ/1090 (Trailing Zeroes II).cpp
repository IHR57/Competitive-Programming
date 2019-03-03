#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

ll factorialFact(ll n, ll p)
{
    ll freq = 0;
    ll x = n;

    while(x){
        freq += (x / p);
        x = x / p;
    }
    return freq;
}

int main()
{
    int test, caseno = 1;
    ll n, r, p, q, num2, num5;

    scanf("%d", &test);

    while(test--){
        num2 = 0, num5 = 0;
        scanf("%lld %lld %lld %lld", &n, &r, &p, &q);
        num2 += factorialFact(n, 2);
        num5 += factorialFact(n, 5);
        ll temp = p, cnt = 0;
        while(temp % 2 == 0){
            cnt++;
            temp /= 2;
        }
        num2 += (cnt * q);
        cnt = 0;
        while(temp % 5 == 0){
            cnt++;
            temp /= 5;
        }
        num5 += (cnt * q);

        num2 -= (factorialFact(r, 2) + factorialFact(n - r, 2));
        num5 -= (factorialFact(r, 5) + factorialFact(n - r, 5));

        ll ans = min(num2, num5);

        printf("Case %d: %lld\n", caseno++, ans);
    }

    return 0;

}
