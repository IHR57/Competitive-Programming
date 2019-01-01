#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

ll lcm(ll a, ll b)
{
    return (a * b) / __gcd(a, b);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll a, b;

    cin>>a>>b;

    ll l = lcm(a, b);

    ll cnt1 = l / a;
    ll cnt2 = l / b;

    if(a > b)
        cnt1++;
    else
        cnt2++;

    if(cnt1 > cnt2)
        cout<<"Dasha"<<endl;
    else if(cnt1 < cnt2)
        cout<<"Masha"<<endl;
    else
        cout<<"Equal"<<endl;

    return 0;
}
