#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

ll Power(ll a, ll b)
{
    ll result = 1;
    for(ll i = 1; i <= b; i++){
        result *= a;
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll k, l;

    cin>>k>>l;
    ll ans = 0;
    for(ll i = 1; ; i++){
        if(Power(k, i) == l){
            ans = i;
            break;
        }
        if(Power(k, i) > l)
            break;
    }
    if(ans){
        cout<<"YES"<<endl;
        cout<<ans-1<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }

    return 0;
}
