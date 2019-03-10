#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

vector<pii> v;
bool compare(pii A, pii B)
{
    return A.first < B.first;
}

int main()
{
    int n, m, a, b;

    cin>>n>>m;

    for(int i = 0; i < n; i++){
        cin>>a>>b;
        v.push_back(make_pair(a, b));
    }

    sort(v.begin(), v.end(), compare);

    ll ans = 0;
    for(int i = 0; i < v.size(); i++){
        int temp = min(m, v[i].second);
        ans += (temp * 1LL * v[i].first);
        m -= temp;
        if(m <= 0)
            break;
    }

    cout<<ans<<endl;

    return 0;
}
