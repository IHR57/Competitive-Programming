//Date: 18/11/19
#include <bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1.0)
#define INF 2147483647
#define MOD 998244353
#define MAX 200005
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

bool check(int mask, int pos) { return (bool) (mask & (1<<pos)); };
void Set(int mask, int pos) { mask = (mask | (1<<pos)); };

string a, b;
int n, m;
ll p2[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cin>>n>>m;
    cin>>a;
    cin>>b;

    vector<int> v;

    p2[0] = 1;      //precal power of 2
    for(int i = 1; i < MAX; i++)
        p2[i] = (p2[i-1] * 2) % MOD;

    for(int i = m - 1, k = 0; i >= 0; i--, k++){
        if(b[i] == '1')
            v.pb(k);
    }

    ll ans = 0;
    for(int i = n - 1, k = 0; i >= 0; i--, k++){
        if(a[i] == '1'){
            int t = lower_bound(v.begin(), v.end(), k) - v.begin();
            int x = v.size() - t;
            ans += (x * p2[k]) % MOD;
            ans %= MOD;
        }
    }

    cout<<ans<<endl;

    return 0;
}