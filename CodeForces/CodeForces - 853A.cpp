#include <bits/stdc++.h>
#define MAX 300005
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int cost[MAX], ans[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    priority_queue<pair<int, int> > pq;

    int n, k;
    cin>>n>>k;

    for(int i = 0; i < n; i++)
        cin>>cost[i];

    for(int i = 0; i < k; i++){
        pq.push(make_pair(cost[i], i));
    }

    ll result = 0;
    for(int i = k; i < n + k; i++){
        if(i < n){
            pq.push(make_pair(cost[i], i));
        }

        pii u = pq.top();
        pq.pop();
        result += (i - u.second) * 1LL * u.first;
        ans[u.second] = i;
    }

    cout<<result<<endl;
    for(int i = 0; i < n; i++)
        cout<<ans[i] + 1<<" ";
    cout<<endl;

    return 0;
}
