#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n;

    cin>>n;

    if(n <= 9){
        cout<<n<<endl;
        return 0;
    }
    ll ans = 0;
    ll p = 10;
    int k = 1;
    while(p <= n){
        ans += (ll) (k * (p - (p/10)));
        k++;
        p *= 10;
    }
    ans += (ll) (k * (n - p/10 + 1));

    cout<<ans<<endl;

    return 0;
}
