//Problem ID: CodeForces 300C (Beautiful Numbers)
//Programmer: IQBAL HOSSAIN     Description: Combinatorics
//Date: 06/01/19
#include <bits/stdc++.h>
#define MAX 1000005
#define MOD 1000000007
using namespace std;

typedef long long ll;

ll fact[MAX];
int a, b;

bool check(int n)
{
    int cnt = 0, d = 0;
    while(n > 0){
        if((n % 10) == a || (n % 10) == b){
            cnt++;
        }
        n /= 10;
        d++;
    }
    if(d == cnt)
        return true;
    return false;
}

ll bigMod(ll a,  ll b)
{
    if(b == 0)
        return 1;
    ll x = bigMod(a, b/2);
    x = (x * x) % MOD;
    if(b % 2 == 1)
        x = (x * a) % MOD;

    return x;
}

ll solve(int n, int r, int k)
{
    return ((fact[n] * bigMod((ll) fact[r], (ll) MOD - 2)) % MOD * bigMod((ll) fact[k], (ll) MOD - 2)) % MOD;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;

    fact[0] = 1;
    for(int i = 1; i < MAX; i++){
        fact[i] = (i * fact[i-1]) % MOD;
    }

    cin>>a>>b>>n;

    ll ans = 0;
    for(int i = 0; i <= n; i++){
        //cout<<a*i+(n-i)*b<<endl;
        if(check(a * i + (n - i) * b)){
            ans = (ans + solve(n, i, n - i)) % MOD;
        }
    }

    cout<<ans<<endl;

    return 0;
}
