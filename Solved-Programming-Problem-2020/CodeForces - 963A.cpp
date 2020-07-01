//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define mem(a, b) (memset(a, b, sizeof(a)))
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define INF 2147483647
#define MOD 1000000009
#define MAX 200005
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> pii;
typedef vector<ii> vii;
typedef priority_queue<int,vector<int>,greater<int> > PQ;
 
int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

ll pow_a[250005], pow_b[250005];
ll n, a, b, k;
int sign[MAX];

ll powmod(ll a, ll b)
{
    ll ans = 1;
    while(b) {
        if(b & 1)
            ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1LL;
    }

    return ans % MOD;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    string str;
    ll firstTerm = 0;

    cin>>n>>a>>b>>k;

    cin>>str;

    for(int i = 0; i < str.size(); i++) {
        sign[i] = (str[i] == '+') ? 1 : -1;
    }
 

    ll ans = 0;

    for(int i = 0; i < k; i++) {
        ll res = ((1LL * sign[i%k] * (powmod(a, n - i) * powmod(b, i)) % MOD) % MOD + MOD) % MOD;
        firstTerm = (firstTerm + res) % MOD;
    }

    int totalTerm = (n + 1) / k;

    ll mul = (powmod(b, k) * powmod(powmod(a, k), MOD - 2)) % MOD;
    if(mul != 1) {
        ans = (powmod(mul, totalTerm) - 1) * powmod(mul - 1, MOD - 2) % MOD;
    }
    else
        ans = totalTerm;

    if(ans < 0)
        ans += MOD;

    cout<<(firstTerm * ans) % MOD<<endl;
 
    return 0;
}