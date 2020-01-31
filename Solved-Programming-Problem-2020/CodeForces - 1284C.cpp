//Date: 05/01/20
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
#define MAX 250005
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

ll n, m, fact[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    cin>>n>>m;
    fact[0] = 1;
    for(int i = 1; i <= n; i++)
        fact[i] = (i * fact[i-1]) % m;

    ll ans = 0;
    for(int i = 1; i <= n; i++){
        ans += (((n - i + 1) * fact[i]) % m * fact[n-i+1]) % m;
    }

    ans %= m;
    cout<<ans<<endl;

    return 0;
}