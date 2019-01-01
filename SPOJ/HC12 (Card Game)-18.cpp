#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAX 10005
#define MOD 1000000007
using namespace std;

typedef long long ll;

ll factorial[MAX];

ll bigMod(ll a, ll b)
{
    if(b == 0)
        return 1;
    ll x = bigMod(a, b/2);
    x = (x * x) % MOD;
    if(b % 2 == 1){
        x = (x * a) % MOD;
    }

    return x;
}

ll calculate(int n, int k)
{
    return (factorial[n] * ((bigMod(factorial[k], MOD - 2) * bigMod(factorial[n-k], MOD - 2)) % MOD)) % MOD;
}

int main()
{
    int test, n, k, caseNo = 1, arr[MAX];

    factorial[0] = 1;

    for(int i = 1; i < MAX; i++){
        factorial[i] = (i * factorial[i-1]) % MOD;
    }

    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &n, &k);
        for(int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
        }

        sort(arr, arr+n);

        int l = k - 1, r = k - 1;      //left corner of given n and k in pascals triangle
        ll result = 0;

        while(l < n){
            result += (calculate(l, r) * arr[l]);
            if(result > MOD)
                result %= MOD;
            l++;        //we will move upper cell
        }

        printf("Case #%d: %lld\n", caseNo++, result);
    }

    return 0;
}
