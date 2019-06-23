#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long  long ll;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll a, b, c, d;
    cin>>a>>b>>c>>d;

    ll g = __gcd(c, d);
    ll l = (c * d) / g;

    ll ans1 = b / c - a / c;
    if(a % c == 0)
        ans1++;
    ll ans2 = b / d - a / d;
    if(a % d == 0)
        ans2++;
    ll ans3 = b / l - a / l;
    if(a % l == 0)
        ans3++;

    ll ans = (b - a + 1) - ans1 - ans2 + ans3;

    cout<<ans<<endl;

    return  0;
}

