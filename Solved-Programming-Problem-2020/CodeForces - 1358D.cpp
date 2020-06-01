//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define mem(a, b) (memset(a, b, sizeof(a)))
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define INF 2147483647
#define MOD 1000000007
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
 
ll arr[2 * MAX];
ll cs[2 * MAX];
ll css[2*MAX];
 
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    ll x;
 
    vector<ll> v;
    int val;
 
    cin>>n>>x;
 
    cs[0] = 0;
    for(int i = 0; i < n; i++) {
        cin>>arr[i];
        v.pb(arr[i]);
        cs[i+1] = cs[i] + arr[i];
    }
    for(int i = 0; i < n; i++) {
        v.pb(arr[i]);
        cs[i+n+1] = cs[i+n] + arr[i];
    }
 
    css[0] = 0;
    for(int i = 0; i < v.size(); i++) {
        css[i+1] = css[i] + ((v[i] * (v[i] + 1)) >> 1LL);
    }
 
    ll ans = 0;
    for(int i = 0; i < 2 * n; i++) {
        if(cs[i+1] >= x) {
            int idx = upper_bound(cs, cs + 2 * n, cs[i+1] - x) - cs;
            ll res = css[i+1] - css[idx];
            ll req = cs[i+1] - cs[idx];
            ll rem = x - req;
            res += ((arr[idx-1] * (arr[idx-1] + 1)) >> 1LL);
            res -= (((arr[idx-1] - rem) * (arr[idx-1] - rem + 1)) >> 1LL);
            ans = max(ans, res);
        }
    }
 
    cout<<ans<<endl;
 
    return 0;
}
 
