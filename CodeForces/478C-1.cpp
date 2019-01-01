#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll color[10];

    cin>>color[0]>>color[1]>>color[2];

    sort(color, color + 3);

    ll result = (color[0] + color[1] + color[2]) / 3;

    if(color[0] + color[1] < result)
        result = color[0] + color[1];

    cout<<result<<endl;

    return 0;
}
