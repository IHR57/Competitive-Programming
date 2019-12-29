//Problem ID: LightOJ - 1319 (Monkey Tradition)
//Programmer: IQBAL HOSSAIN     Description: Chinese Remainder Theorem
//Date: 01/05/19
//References: https://www.geeksforgeeks.org/chinese-remainder-theorem-set-2-implementation/
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

ll ext_gcd ( ll A, ll B, ll *X, ll *Y ){
    ll x2, y2, x1, y1, x, y, r2, r1, q, r;
    x2 = 1; y2 = 0;
    x1 = 0; y1 = 1;
    for (r2 = A, r1 = B; r1 != 0; r2 = r1, r1 = r, x2 = x1, y2 = y1, x1 = x, y1 = y ) {
        q = r2 / r1;
        r = r2 % r1;
        x = x2 - (q * x1);
        y = y2 - (q * y1);
    }
    *X = x2; *Y = y2;
    return r2;
}


ll mod_inv(ll a, ll b)
{
    ll x, y;
    ll g = ext_gcd(a, b, &x, &y);
    return (x + b) % b;
}

ll CRT(vector<ll> A, vector<ll> M)
{
    ll ans = 0;
    int n = A.size();
    ll prod = 1;
    for(int i = 0; i < n; i++)
        prod = prod * M[i];

    for(int i = 0; i < n; i++){
        ll t = ((prod / M[i]) * A[i]) % prod;
        t = (t * mod_inv(prod / M[i], M[i])) % prod;
        ans = (ans + t) % prod;
    }

    return ans;
}

int main()
{
    int test, caseno = 1, p, r;
    int n;
    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);
        vector<ll> a, m;
        for(int i = 0; i < n; i++){
            scanf("%d %d",  &p, &r);
            a.push_back((ll) r);
            m.push_back((ll) p);
        }

        ll result = CRT(a, m);

        printf("Case %d: %lld\n", caseno++, result);
    }

    return 0;
}
