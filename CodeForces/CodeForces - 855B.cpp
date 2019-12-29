#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

ll pref[MAX], suff[MAX], p, q, r;
int n, arr[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;

    cin>>n>>p>>q>>r;

    for(int i = 1; i <= n; i++){
        cin>>arr[i];
    }

    ll inf = -4e18;

    pref[0] = inf;
    for(int i = 1; i <= n; i++){
        pref[i] = max(pref[i-1], p * arr[i]);
    }
    suff[n+1] = inf;
    for(int i = n; i >= 1; i--){
        suff[i] = max(suff[i+1], r * arr[i]);
    }

    ll ans = inf;
    for(int i = 1; i <= n; i++){
        ans = max(ans, pref[i] + suff[i] + q * arr[i]);
    }

    cout<<ans<<endl;

    return 0;
}
