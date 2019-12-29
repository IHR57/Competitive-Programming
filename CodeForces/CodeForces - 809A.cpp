#include <bits/stdc++.h>
#define MAX 300005
#define MOD 1000000007
using namespace std;

typedef long long ll;

ll bigMod(ll a, ll b)
{
    if(b == 0)
        return 1;
    ll x = bigMod(a, b / 2);
    x = (x * x) % MOD;
    if(b % 2 == 1)
        x = (x * a) % MOD;
    return x;
}

int arr[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;

    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    sort(arr, arr + n);

    ll ans = 0;
    for(int i = 1; i < n; i++){
        ll temp = (ll) arr[i] - (ll) arr[i-1];
        ans = (ans + temp * (bigMod(2, i) - 1) % MOD * (bigMod(2, n - i) - 1) % MOD) % MOD;
    }

    cout<<ans<<endl;

    return 0;
}
