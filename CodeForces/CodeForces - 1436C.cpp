//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define mem(a, b) (memset(a, b, sizeof(a)))
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define min3(a,b,c)     min(a,min(b,c))
#define max3(a,b,c)     max(a,max(b,c))
#define min4(a,b,c,d)   min(a,min(b,min(c,d)))
#define max4(a,b,c,d)   max(a,max(b,max(c,d)))
#define FOR(i,a,b)      for(int i=a;i<=b;i++)
#define ROF(i,a,b)      for(int i=a;i>=b;i--)
#define REP(i,b)        for(int i=0;i<b;i++)
#define all(v)          v.begin(),v.end()
#define SORT(v)         sort(v.begin(),v.end())
#define RSORT(v)        sort(v.rbegin(),v.rend())
#define REV(v)          reverse(v.begin(),v.end())
#define INF 2147483647
#define EPS 1e-8
#define MOD 1000000007
#define MAX 300005
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> pii;
typedef pair<ll, ll> LL;
typedef vector<ii> vii;
typedef priority_queue<int,vector<int>,greater<int> > PQ;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int setBit(int mask, int pos){return mask = mask | (1<<pos);}
bool checkBit(int mask, int pos){return (bool)(mask & (1<<pos));}

ll fact[MAX];

ll powmod(ll a, ll b)
{
    ll ans = 1;
    while(b) {
        if(b & 1)
            ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1LL;
    }

    return ans;
}

void solve()
{
    fact[0] = 1;

    int n, x, pos;
    cin>>n>>x>>pos;

    FOR(i, 1, n) {
        fact[i] = (i * fact[i-1]) % MOD;
    }

    int low = 0, high = n;

    int mn = 0, mx = 0;

    while(low < high) {
        int mid = (low + high) / 2;
        if (pos == mid) {
            low = mid + 1;
        }
        else {
            if (pos < mid) {
                mx++;
                high = mid;
            } else {
                mn++;
                low = mid + 1;
            }
        }
    }

    //cout<<mx<<" "<<mn<<endl;
    int bigger = n - x, smaller = x - 1, other = n - mx - mn - 1;

    ll ans = 0;
    ll ans1 = (fact[bigger] * powmod(fact[bigger- mx], MOD - 2)) % MOD;
    ll ans2 = (fact[smaller] * powmod(fact[smaller - mn], MOD - 2)) % MOD;
    ans = ((ans1 * ans2) % MOD * fact[other]) % MOD;

    if(bigger - mx < 0 || smaller - mn < 0) {
        ans = 0;
    }

    cout<<ans<<endl;

    return;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int test = 1;

    //cin>>test;

    while(test--) {
        solve();
    }

    return 0;
}

