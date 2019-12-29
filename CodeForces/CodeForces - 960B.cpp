#include <bits/stdc++.h>
#define MAX 1005
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k1, k2, a[MAX], b[MAX], diff[MAX];

    priority_queue<int> pq;
    cin>>n>>k1>>k2;

    for(int i = 0; i < n; i++){
        cin>>a[i];
    }

    for(int i = 0; i < n; i++){
        cin>>b[i];
    }

    for(int i = 0; i < n; i++){
        diff[i] = abs(a[i] - b[i]);
        pq.push(diff[i]);
    }

    int k = k1 + k2;

    while(k > 0){
        int u = pq.top();
        pq.pop();
        pq.push(abs(u - 1));
        k--;
    }

    ll ans = 0;
    while(!pq.empty()){
        int u = pq.top();
        ans += ((ll) u * (ll) u);
        pq.pop();
    }

    cout<<ans<<endl;

    return 0;
}
