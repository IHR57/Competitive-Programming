//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int w1, h1, w2, h2;

    cin>>w1>>h1>>w2>>h2;

    int ans1 = 2 * (h1 + 1) + w1 + (w1 - w2);
    int ans2 = 2 * (h2 + 1) + w2;

    cout<<ans1 + ans2<<endl;

    return 0;
}
