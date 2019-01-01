// BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, k;

    cin>>n>>k;

    if(k >= 2 * n){
        cout<<0<<endl;
        return 0;
    }
    ll ans;
    if(k <= n){
        ans = (k - 1) / 2;
    }
    else{
        ll temp = (k - n);
        ll s = (n - temp + 1);
        ans = s / 2;
    }

    cout<<ans<<endl;

    return 0;
}
