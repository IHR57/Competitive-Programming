#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

ll bs(ll x)             //return sqrt of x
{
    ll low = 0, high = 1e9 + 1;
    while(low < high - 1){
        ll mid = (low + high) >> 1;
        if(mid * mid > x)
            high = mid;
        else
            low = mid;
    }
    return low;
}

set<ll> s;
vector<ll> v;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll q, l, r;

    s.insert(1);
    ll Max = 1e18;
    for(ll i = 2; i <= 1e6; i++){
        for(ll j = i * i * i; j <= Max; j *= i){
            s.insert(j);
            if(j > Max / i)
                break;
        }
    }

    set<ll> :: iterator it;

    for(it = s.begin(); it != s.end(); it++){
        ll x = *it;
        ll temp = bs(x);
        if(temp * temp != x){
            v.push_back(x);
        }
    }

    cin>>q;
    for(ll i = 0; i < q; i++){
        cin>>l>>r;
        ll sum = upper_bound(v.begin(), v.end(), r) - lower_bound(v.begin(), v.end(), l);
        //cout<<sum<<endl;
        sum += bs(r) - bs(l-1);

        cout<<sum<<endl;
    }

    return 0;
}
