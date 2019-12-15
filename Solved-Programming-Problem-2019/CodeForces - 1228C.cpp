//Date: 18/11/19
#include <bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1.0)
#define INF 2147483647
#define MOD 1000000007
#define MAX 100005
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int primes[MAX/10], mark[MAX], counter = 0;

void genSieve()
{
    int limit = sqrt(MAX + 1);

    mark[1] = 1;
    for(int i = 4; i < MAX; i += 2)
        mark[i] = 1;

    primes[counter++] = 2;
    for(int i = 3; i < MAX; i += 2){
        if(!mark[i]){
            primes[counter++] = i;
            if(i <= limit){
                for(int j = i * i; j < MAX; j += i * 2)
                    mark[j] = 1;
            }
        }
    }
}

vector<int> primeFactors(ll n)
{
    int idx = 0;
    ll pf = (ll) primes[idx];
    vector<int> factors;
    while(pf * pf <= n){
        if(n % pf == 0){
            while(n % pf == 0){
                n /= pf;
            }
            factors.pb(pf);
        }
        pf = (ll) primes[++idx];
    }

    if(n != 1)
        factors.pb(n);

    return factors;
}

ll powmod(ll a, ll b)
{
    ll res = 1;
    while(b){
        if(b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }

    return res;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    genSieve();
    ll x, n;

    cin>>x>>n;

    vector<int> factors = primeFactors(x);

    ll ans = 1;
    for(int i = 0; i < factors.size(); i++){
        ll t = n, s = 0;
        while(t){
            s += t / factors[i];
            t = t / factors[i];
        }
        ans = (ans * powmod((ll) factors[i], s)) % MOD;
    }

    cout<<ans<<endl;

    return 0;
}