#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main()
{
    int H, W, h, w;
    cin>>H>>W;
    cin>>h>>w;

    int ans = (H - h) * (W - w);

    cout<<ans<<endl;

    return 0;
}
