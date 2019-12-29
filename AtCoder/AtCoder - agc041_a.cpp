//Date: 28/12/19
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
    ll n, a, b;

    cin>>n>>a>>b;

    if((b - a) % 2 == 0){
        ll ans = (b - a) / 2;
        ans = min(ans, min(b - 1, n - a));
        cout<<ans<<endl;
    }
    else{
        ll ans, res;
        ll ta = a, tb = b;
        ans += (n - tb);
        ta += (n - tb) + 1;
        ans++;
        ans += (n - ta) / 2;
        res = ans;
        ans = 0;
        ta = a, tb = b;
        ans += (ta - 1);
        tb -= (ta - 1) + 1;
        ans++;
        ans += (tb - 1) / 2;
        res = min(res, ans);
        cout<<res<<endl;
    }
    return 0;
}
