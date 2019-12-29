/*
Template for vjudge.net

	Author: Iqbal Hossain Rasel
	CodeForces: The_Silent_Man
	AtCoder   : IHR57
	TopCoder  : IHR57

*/
#include <bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define pi 3.1415926535897932384
#define INF 2147483647
#define EPS 1e-8
#define MOD 1000000007
#define MAX 100005
using namespace std;

typedef long long ll;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

set<ll> s;
vector<ll> v, d;
ll cs[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif

    ll l, r, val;
    int n, q;

    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>val;
        s.insert(val);
    }
    ll ans = s.size();
    for(set<ll> :: iterator it = s.begin(); it != s.end(); it++){
        v.pb(*it);
    }
    for(int i = 1; i < v.size(); i++){
        ll x = (v[i] - v[i-1] - 1);
        if(x != 0)
            d.pb(x);
    }

    sort(d.begin(), d.end());

    if(!d.empty()){
        cs[0] = d[0];
        for(int i = 1; i < d.size(); i++){
            cs[i] = cs[i-1] + d[i];
        }
    }

    cin>>q;

    for(int i = 0; i < q; i++){
        ans = s.size();
        cin>>l>>r;
        if(s.size() == 1){
            cout<<(r - l + 1)<<endl;
            continue;
        }
        r -= l;
        int idx = lower_bound(d.begin(), d.end(), r) - d.begin();
        int sz = (d.size() - idx);
        ans += (r * sz);
        if(idx != 0)
            ans += cs[idx-1];
        ans += r;
        cout<<ans<<" ";
    }
    cout<<endl;

    return 0;
}
