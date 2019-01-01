#include <bits/stdc++.h>
#define MAX 1005
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int a, b, c, d, fst, snd;

    cin>>a>>b>>c>>d;

    int g = __gcd(a, c);
    int lcm = (a * c) / g;

    int w = a * (lcm / a);
    int x = b * (lcm / a);
    int y = c * (lcm / c);
    int z = d * (lcm / c);

    fst = fabs(x- z);
    snd = max(x, z);

    g = __gcd(fst, snd);

    cout<<fst / g<<"/"<<snd / g<<endl;

    return 0;
}
