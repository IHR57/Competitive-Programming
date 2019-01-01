#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, m;

    cin>>n>>m;

    ll team = n / m;
    ll remaining = n % m;

    ll Min = ((m - remaining) * ((team * (team - 1)) / 2)) + (remaining * (team * (team + 1)) / 2);
    ll temp = n - (m - 1);
    ll Max = (temp * (temp - 1)) / 2;

    cout<<Min<<" "<<Max<<endl;

    return 0;
}
