//Problem ID: CodeChef - COPR16G (Get AC in one go)
//Programmer: IQBAL HOSSAIN     Description: GCD
//Date: 26/04/19
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int main()
{
    int test;
    ll a, b;

    scanf("%d", &test);

    while(test--){
        scanf("%lld %lld", &a, &b);
        ll  ans = -1;
        if(__gcd(a, b) == 1)
            ans = (a * b - a - b) + 1;
        printf("%lld\n", ans);
    }

    return 0;
}
