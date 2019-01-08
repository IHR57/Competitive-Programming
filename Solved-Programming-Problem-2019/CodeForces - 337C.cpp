//Problem ID: CodeForces - 337C (Quiz)
//Programmer: IQBAL HOSSAIN     Description: Math
//Date: 07/01/19
#include <bits/stdc++.h>
#define MAX 100005
#define MOD 1000000009
using namespace std;

typedef long long ll;

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

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, m, k;

    cin>>n>>m>>k;

    ll temp = (k - 1) * (n / k) + (n % k);
    if(temp >= m){
        cout<<m<<endl;
        return 0;
    }
    ll ans = 0;

    ans = (bigMod(2, m - temp + 1) * k) % MOD;
    ans = ((ans % MOD) + (m - k * (m - temp + 2)) % MOD) % MOD;

    if(ans < 0)
        ans += MOD;

    cout<<ans<<endl;

    return 0;
}
