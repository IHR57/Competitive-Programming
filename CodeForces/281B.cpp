#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll x, y, n, ans1, ans2;

    cin>>x>>y>>n;

    double frac = (double) x / (double) y, Min = 1000000.0;

    for(int i = 1; i <= n; i++){
        ll l = 0, r = 100001, mid;
        ll a, b;
        double k;
        while(r - l > 1){
            mid = (l + r) >> 1;
            if((double) mid / i < frac)
                l = mid;
            else
                r = mid;
        }
        if(fabs((double) l / i - frac) <= fabs((double) r / i - frac)){
            k = (double) fabs((double) l / i - frac);
            a = l;
            b = i;
        }
        else{
            k = (double) fabs((double) r / i - frac);
            a = r;
            b = i;
        }
        if(k < Min){
            Min = k;
            ans1 = a;
            ans2 = b;
        }
        //cout<<ans1<<" "<<ans2<<endl;
    }

    cout<<ans1<<"/"<<ans2<<endl;

    return 0;
}
