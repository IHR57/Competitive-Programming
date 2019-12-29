//Problem ID: CodeForces - 1140C (Playlist)
//Programmer: IQBAL HOSSAIN     Description: Sorting
//Date: 07/04/19
#include <bits/stdc++.h>
#define MAX 300005
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
priority_queue<int, vector<int>, greater<int> > pq;

bool compare(pii A, pii B)
{
    return A.first > B.first;
}

pii v[MAX];

int main()
{
    int n, k;
    cin>>n>>k;

    for(int i = 1; i <= n; i++){
        cin>>v[i].second>>v[i].first;
    }

    sort(v + 1, v + n + 1, compare);

    ll sum = 0, ans = -1;

    for(int i = 1; i <= n; i++){
        ll m = (ll) v[i].first;
        sum += (ll) v[i].second;
        pq.push(v[i].second);
        if(pq.size() > k){
            int temp = pq.top();
            pq.pop();
            sum -= temp;
        }
        ans = max(ans, m * sum);
    }

    cout<<ans<<endl;

    return 0;
}
