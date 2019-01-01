#include <bits/stdc++.h>
#define MOD 1000000007
#define MAX 1005
using namespace std;

typedef long long ll;

ll factorial[MAX];

ll bigMod(ll a, ll b)
{
    if(b == 0)
        return 1;
    ll x = bigMod(a, b / 2);
    x = (x * x) % MOD;
    if(b % 2 == 1){
        x = (x * a) % MOD;
    }

    return x;
}

ll nCk(ll n, ll k)
{
    return (factorial[n] * ((bigMod(factorial[k], MOD - 2) * bigMod(factorial[n-k], MOD - 2)) % MOD)) % MOD;
}

int main()
{
    int test, caseNo = 1, n, m, k;

    factorial[0] = 1;
    for(int i = 1; i < MAX; i++){
        factorial[i] = (i * factorial[i-1]) % MOD;
    }

    scanf("%d", &test);

    while(test--){
        scanf("%d %d %d", &n, &m, &k);
        ll ans = factorial[n-k];
        ll rem = m - k, temp = 0;
        for(int i = 1; i <= rem; i++){
            ans -= ((i & 1) ? 1: -1) * (nCk(rem, i) * factorial[n-k-i]) % MOD;
            ans = (ans + MOD) % MOD;
        }

        ll mul = nCk(m, k);
        //cout<<mul<<" "<<ans<<endl;
        printf("Case %d: %lld\n", caseNo++, (mul * ans) % MOD) ;
    }

    return 0;
}
