#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll x, y, p, q, low, high, mid, ans;
    int test;

    cin>>test;

    while(test--){
        cin>>x>>y>>p>>q;

        low = 1, high = 10000000000;

        ans = -1;
        while(low <= high){
            mid = (low + high + 1) >> 1;
            ll t1 = p * mid;
            ll t2 = q * mid;
            if(t1 >= x && t2 >= y && (t1 - x) <= (t2 - y)){     //increased number in upper must be less or equal then under
                ans = q * mid - y;      //this is our answer
                high = mid - 1;     //find smallest possible
            }
            else{
                low = mid + 1;
            }
        }

        cout<<ans<<endl;
    }

    return 0;
}
