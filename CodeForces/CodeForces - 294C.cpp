//Problem ID:  CodeForces - 294C (Shaass and Lights)
//Programmer: IQBAL HOSSAIN     Description: Combinatorics
//Date: 06/02/19
//Problem Link: https://codeforces.com/problemset/problem/294/C
#include <bits/stdc++.h>
#define MAX 1005
#define MOD 1000000007
using namespace std;

typedef long long ll;

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

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll fact[MAX];
    int k;

    fact[0] = 1;
    for(int i = 1; i < MAX; i++){
        fact[i] = (i * fact[i-1]) % MOD;
    }

    int start = 1, switches[MAX];
    ll n, m;

    cin>>n>>m;

    ll res = fact[n - m];

    for(int i = 0; i < m; i++){
        cin>>switches[i];
    }

    sort(switches, switches + m);

    ll temp = 1;
    for(int i = 0; i < m; i++){
        k = (switches[i] - start);
        temp = (temp * fact[k]) % MOD;
        start = switches[i] + 1;
    }

    temp = (temp * fact[n - switches[m-1]]) % MOD;

    ll ans = (res * bigMod(temp, MOD - 2)) % MOD;

    for(int i = 1; i < m; i++){
        k = (switches[i] - switches[i-1] - 2);
        if(k > 0){
            ans = (ans * bigMod(2, (ll) k)) % MOD;
        }
    }

    cout<<ans % MOD<<endl;

    return 0;
}
