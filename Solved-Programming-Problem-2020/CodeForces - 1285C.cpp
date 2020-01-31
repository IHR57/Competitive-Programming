#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define pi 3.1415926535897932384
#define INF 2147483647
#define EPS 1e-8
#define MOD 1000000007
#define MAX 200005
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

ll arr[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ll x;

    cin>>x;

    vector<ll> v;
    for(ll i = 1; i * i <= x; i++){
        if(x % i == 0){
            v.pb(i);
            if(x / i != i){
                v.pb(x / i);
            }
        }
    }

    sort(v.begin(), v.end());

    ll a = 1, b = x, Min = x;
    for(int i = 0, j = v.size() - 1; i < j; i++, j--){
        if(__gcd(v[i], v[j]) == 1){
            ll t = max(v[i], v[j]);
            if(t < Min){
                Min = t;
                a = v[i], b = v[j];
            }
        }
    }

    cout<<a<<" "<<b<<endl;

    return 0;
}
