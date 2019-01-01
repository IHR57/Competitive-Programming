#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, x, y;

    cin>>n>>x>>y;

    n /= 2;

    if((x == n || x == n + 1) && (y == n || y == n + 1))
        cout<<"NO"<<endl;
    else
        cout<<"YES"<<endl;

    return 0;
}
