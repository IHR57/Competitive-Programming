#include <bits/stdc++.h>
#define MAX 1000005
#define MOD 1000000007
using namespace std;

typedef long long ll;

ll compute(ll x)
{
    ll cnt1 = 0, cnt2 = 0;
    for(int i = 0; ; i++){
        if(i % 2 == 0){
            if((1LL<<i) > x){
                cnt1 = (cnt1 + x) % MOD;
                break;
            }
            else
                cnt1 = (cnt1 + (1LL<<i)) % MOD;
        }
        else{
            if((1LL<<i) > x){
                cnt2 = (cnt2 + x) % MOD;
                break;
            }
            else
                cnt2 = (cnt2 + (1LL<<i)) % MOD;
        }
        x -= (1LL<<i);
        if(x <= 0)
            break;
    }

    return ((cnt1 * cnt1) % MOD + (cnt2 * (cnt2 + 1)) % MOD) % MOD;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll L, R;

    cin>>L>>R;
    ll ans = compute(R) - compute(L - 1);
    if(ans < 0)
        ans += MOD;

    cout<<ans<<endl;
    
    return 0;
}