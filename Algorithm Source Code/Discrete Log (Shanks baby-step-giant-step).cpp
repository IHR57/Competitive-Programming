/*
    given a^x = b (mod m)
    calculate x which satisfies the equation where a and m are relatively prime; otherwise it will not work
    This algorithm is called Shanks Baby-Step-Giant-Step algorithm

    we can write: x = n * p - q; where n is pre-selected constant; p is Giant-step because if we increase p by 1
    then x will be increased by n and q is called baby-step

    any number x in the interval[0;m] can be represented as x = n * p - q;
    p lies on the interval [1; m / n]; and q lies on [0;n];

    so we can write a^(np - q) = b (mod m) ; a^(np) = ba^q; n = sqrt(m);
    we can use meet-in-the-middle technique i.e first we will calculate all values for left-hand side then
    we will find out our required p when calculating value for the right-side using binary-search or using map

    References: https://cp-algorithms.com/algebra/discrete-log.html

    Another Method:

        given a^x = b (mod N)
        choose some k normally k = sqrt(N);
        evaluate: a^1, a^2 ... a^(k-1)
        evaluate: ba^(-k), ba^(-2k), ba^(-3k) ... ba^(-rk)      stop when r * k > N
        if the DLP has solution there will be one value common in both lists

        let the common elements be a^n and ba^(-mk)

            a^n = ba^(-mk) mod N
            a^(mk + n) = b mod N

            then (mk + n) is our solution

    References: https://youtu.be/007MVsELvQw
*/

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

    while(cin>>a>>b){
        ll result = solve(a, b, MOD);
        cout<<result<<endl;
    }

    return 0;
}
