//Date: 27/10/19
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
typedef pair<int, int> ii;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif

    ll n;

    cin>>n;
    ll ans = 1e16;
    for(ll i = 2; i * i <= n; i++){
    	if(n % i == 0){
    		ans = min(ans, (i - 1) + (n / i - 1));
    	}
    }

    ans = min(ans, n - 1);

    cout<<ans<<endl;

    return 0;
}
