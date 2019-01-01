#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>
#define MAX 100005
using namespace std;

typedef long long ll;

ll solve(ll a, ll b)
{
    ll sum = 0;
    while(a % b != 0){
        sum += (a/b);
        ll temp = a;
        a = b;
        b = (temp % b);
    }

    sum += (a/b);

    return sum;
}

int main()
{
    int test, caseno = 1;
    ll a, b;

    scanf("%d", &test);

    while(test--){
        scanf("%lld %lld", &a, &b);
        ll ans;
        if(a == 0 && b == 0){
            printf("Case #%d: 1\n", caseno++);
            continue;
        }
        else if(a == 0 || b == 0){
            printf("Case #%d: 2\n", caseno++);
            continue;
        }
        if(b > a)
            swap(a, b);
        if(a == b){
            ans = 2;
        }
        else if(a % b == 0){
            ans = (a / b) + 1;
        }
        else{
            ans = solve(a, b) + 1;
        }

        printf("Case #%d: %lld\n", caseno++, ans);
    }

    return 0;
}
