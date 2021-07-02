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
#define MOD 998244353
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

int arr[MAX];

int sod(vector<int> v)
{
    int sum = 0;
    REP(i, v.size())
        sum += v[i];

    return sum;
}

void solve()
{
    ll n, x;

    cin>>n>>x;

    ll tn = n;
    vi digits;

    while(tn) {
        digits.pb(tn % 10);
        tn /= 10;
    }
    digits.pb(0);

    REV(digits);

    if(sod(digits) <= x) {
        cout<<0<<endl;
        return;
    }

    ROF(i, digits.size() - 1, 1) {
        digits[i] = 0;
        int carry = 1;
        ROF(j, i - 1, 0) {
            int tx = (carry + digits[j]);
            carry = (tx >= 10) ? 1 : 0;
            digits[j] = tx % 10;
        }
        if(sod(digits) <= x) {
            ll p = 1, ans = 0;
            ROF(j, digits.size() - 1, 0) {
                ans += (digits[j] * p);
                p *= 10;
            }
            cout<<(ans - n)<<endl;
            return;
        }
    }

    return;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int test = 1;

    cin>>test;

    while(test--) {
        solve();
    }

    return 0;
}

