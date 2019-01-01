#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll x, y, a, b;

    cin>>x>>y>>a>>b;

    ll temp = __gcd(x, y), ans;
    temp = (x * y) / temp;

    if(a % temp == 0){
        ans = (b/temp - a/temp + 1);
    }
    else{
        ans = (b/temp - a/temp);
    }

    cout<<ans<<endl;

    return 0;
}
