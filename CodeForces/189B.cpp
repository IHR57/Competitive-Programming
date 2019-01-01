#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int w, h;

    int bx, by, cx, cy, dx, dy;

    int cnt = 0;

    cin>>w>>h;

    ll ans = 0;
    for(int i = 2; i <= w; i += 2){
        for(int j = 2; j <= h; j += 2){
            ans += (w - i + 1) * (h - j + 1);
        }
    }

    cout<<ans<<endl;

    return 0;
}
