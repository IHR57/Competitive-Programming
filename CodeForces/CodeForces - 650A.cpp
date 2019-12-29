//Date: 01/04/19
#include <bits/stdc++.h>
#define MAX 200005
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, u, v, t;
    map<int, int> mp1, mp2;
    map<pii, int> MP;

    cin>>n;

    ll ans = 0;
    for(int i = 0; i < n; i++){
        cin>>u>>v;
        ans += (mp1[u]++);
        ans += (mp2[v]++);
        ans -= (MP[(make_pair(u, v))]++);
    }

    cout<<ans<<endl;

    return 0;
}
