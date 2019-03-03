//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 200005
using namespace std;

typedef long long ll;

vector<ll> v[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, arr[MAX];

    int val;

    cin>>n;

    for(int i = 0; i < 2 * n; i++){
        cin>>val;
        v[val].push_back(i);
    }

    ll ans1 = 0, ans2 = 0;
    int idx1 = 0, idx2 = 0;
    for(int i = 1; i <= n; i++){
        ans1 += abs(v[i][0] - idx1);
        idx1 = v[i][0];
        ans2 += abs(v[i][1] - idx2);
        idx2 = v[i][1];
    }

    cout<<ans1 + ans2<<endl;

    return 0;
}
