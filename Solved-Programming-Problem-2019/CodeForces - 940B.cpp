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
#define MAX 200005
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
    ll n,  k, a, b;

    cin>>n>>k>>a>>b;

    if(k == 1){
        cout<<(1LL * n * a) - a<<endl;
        return 0;
    }

    ll x = n, ans = 0;
    while(x != 1){
        if(x % k != 0){
            ans += (a * (x % k));
            x -= (x % k);
        }
        else{
            ans += min(b, (x - (x / k)) * a);
            x = x / k;
        }
        if(x == 0){
            ans -= a;
            break;
        }
    }

    cout<<ans<<endl;

    return 0;
}
