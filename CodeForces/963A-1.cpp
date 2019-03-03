#include <bits/stdc++.h>
#define MAX 100005
#define MOD 1000000009
using namespace std;

typedef long long ll;

ll z, n, a, b, k, temp, x;

ll bigMod(ll a, ll b)
{
    if(b == 0)
        return 1;
    ll x = bigMod(a, b/2);
    x = (x * x) % MOD;
    if(b % 2 == 1)
        x = (x * a) % MOD;

    return x;
}

ll modInv(ll i)
{
    return bigMod(x, i);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string str;

    cin>>n>>a>>b>>k;
    cin>>str;

    z = 0;
    for(int i = 0; i < k; i++){
        if(str[i] == '+')
            z = (z + (bigMod(a, n-i) * bigMod(b, i)) % MOD)  % MOD;
        else
            z = (z - (bigMod(a, n-i) * bigMod(b, i)) % MOD + MOD) % MOD;
    }

    temp = (bigMod(b, MOD) * bigMod(a, MOD - 2)) % MOD;
    x = bigMod(temp, k);

    ll sum = 0;
    for(int i = 0; i <= (n + 1) / k - 1; i++){
        sum = (sum + (z * modInv((ll) i)) % MOD + MOD) % MOD;
    }

    int j = (n + 1) / k;

    //cout<<sum<<endl;
    for(ll i = k*j; i <= n; i++){
        if(str[i%k] == '+')
            sum = (sum + (bigMod(a, n-i) * bigMod(b, i) % MOD)) % MOD;
        else
            sum = (sum - (bigMod(a, n-i) * bigMod(b, i)) % MOD + MOD) % MOD;
    }

    cout<<sum<<endl;

    return 0;

}
