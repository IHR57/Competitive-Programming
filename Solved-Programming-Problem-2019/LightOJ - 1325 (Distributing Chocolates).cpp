//Problem ID: LightOJ - 1325 (Distributing Chocolates)
//Programmer: IQBAL HOSSAIN     Description: Discrete Log (Shanks Baby-step-giant-step)
//Date: 26/02/19
//Problem Link: http://lightoj.com/volume_showproblem.php?problem=1325
#include <bits/stdc++.h>
#define MAX 100005
#define MOD 100000007
using namespace std;

typedef long long ll;

ll powmod(ll a, ll b, ll m) {
    if(b == 0)
        return 1;
    ll x = powmod(a, b / 2, m);
    x = (x * x) % m;
    if(b % 2 == 1)
        x = (x * a) % m;

    return x;
}

ll solve(ll a, ll b, ll m) {
    ll n = (ll) sqrt (m + .0) + 1;

    ll an = 1;
    map<ll, ll> vals;
    for(int i = 0; i < n; i++){
        if(!vals.count(an))
            vals[an] = i;
        an = (an * a) % m;
    }

    ll ret = powmod(a, m - 2, m);
    ret = powmod(ret, n, m);

    ll cur = b;
    for(int i = 0; i < n; i++){
        if(vals.count(cur)){
            return i * n + vals[cur];
        }
        else{
            cur = (cur * ret) % m;
        }
    }

    return -1;
}

int main()
{
    ll a, b;
    int test, caseno = 1;

    scanf("%d", &test);

    while(test--){
        scanf("%lld %lld", &a, &b);
        ll result = solve(a, b, MOD);

        printf("Case %d: %lld\n", caseno++, result);
    }

    return 0;
}
