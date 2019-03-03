#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n;

    cin>>n;

    ll result = (n - 1) * (n - 3) + 1;

    cout<<result<<endl;

    return 0;
}
