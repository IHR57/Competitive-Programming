#include <bits/stdc++.h>
#define MAX 35
using namespace std;

typedef long long ll;

ll c[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    ll  l;

    cin>>n>>l;

    for(int i = 0; i < n; i++)
        cin>>c[i];

    for(int i = 1; i < n; i++)
        c[i] = min(c[i], 2 * c[i-1]);

    ll sum = 0, ans = 2e18;
    for(int i = n - 1; i >= 0; i--){
        ll x = l / (1 << i);
        sum += (x * c[i]);
        l -= (x << i);
        ans = min(ans, sum + (l > 0) * c[i]);
    }

    cout<<ans<<endl;

    return 0;
}
