/*References:
    https://www.geeksforgeeks.org/chinese-remainder-theorem-set-2-implementation/
    https://www.youtube.com/watch?v=ru7mWZJlRQg
*/

#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

ll bigMod(ll a, ll b, ll m)
{
    if(b == 0)
        return 1;
    ll x = bigMod(a, b / 2, m);
    x = (x * x) % m;
    if(b % 2 == 1)
        x = (x * a) % m;
    return x;
}

ll mod_inv(ll a, ll b)
{
    return bigMod(a, b - 2, b);
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
