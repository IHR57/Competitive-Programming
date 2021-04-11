//Date: 10/01/20
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
 
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ll m, x, d;
    ll n;
 
    cin>>n>>m;
 
    ll ans = 0;
    for(int i = 0; i < m; i++){
        cin>>x>>d;
        ans += (n * 1LL * x);
        if(d >= 0){
            ll temp = n * (n - 1) / 2;
            ans += (1LL * temp * d);
        }
        else{
            ll temp = (((n - 1) / 2) * 1LL * ((n - 1) / 2 + 1));
            if(n % 2 == 0){
                temp += (ll) (n / 2);
            }
            ans += (1LL * temp * d);
        }
    }
    cout<<fixed<<setprecision(12);
    cout<<(double) ans / n<<endl;
 
    return 0;
}