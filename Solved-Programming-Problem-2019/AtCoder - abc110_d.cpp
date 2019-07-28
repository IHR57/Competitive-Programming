#include <bits/stdc++.h>
#define MAX 100005
#define pb push_back
#define INF 2147483647
#define MOD 1000000007
using namespace std;

typedef long long ll;

vector<int> factorize(int n)
{
    vector<int> v;
    for(int i = 2; i * i <= n; i++){
        while(n % i == 0){
            v.pb(i);
            n /= i;
        }
    }

    if(n != 1)
        v.pb(n);
    return v;
}

ll powMod(ll a, ll b)
{
    ll res = 1;
    while(b > 0){
        if(b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }

    return res;
}

ll fact(int n)
{
    ll res = 1;
    for(int i = 1; i <= n; i++){
        res = (res * i) % MOD;
    }

    return res;
}

ll solve(int n, int r)
{
    ll res = 1;
    n = n + r - 1;
    for(int i = n; i >= n - r + 1; i--){
        res = (1LL * res * i) % MOD;
    }
    res = (res * powMod(fact(r), MOD - 2)) % MOD;
    return res;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n, m;

    cin>>n>>m;

    map<ll, ll> mp;
    vector<int> factor = factorize(m);
    
    for(int i = 0; i < factor.size(); i++){
        mp[factor[i]]++;
    }

    ll ans = 1;
    for(map<ll, ll> :: iterator it = mp.begin(); it != mp.end(); it++){
        ans = (ans * solve(n, it->second)) % MOD;
        //cout<<solve(n, it->second)<<endl;
    }

    cout<<ans<<endl;

    return 0;
}