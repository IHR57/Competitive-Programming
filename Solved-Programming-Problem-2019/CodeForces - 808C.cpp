#include <bits/stdc++.h>
#define MAX 105
using namespace std;

typedef pair<int, int> pii;
vector<pii> v;
int ans[MAX];

bool compare(pii A,  pii B)
{
    if(A.second == B.second)
        return A.first < B.first;
    return A.second > B.second;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, w,val;

    cin>>n>>w;

    for(int i = 0; i < n; i++){
        cin>>val;
        v.push_back(make_pair(i, val));
    }

    sort(v.begin(), v.end(), compare);

    int sum = 0;
    for(int i = 0; i < v.size(); i++){
        int res = v[i].second >> 1;
        if(v[i].second & 1)
            res++;
        sum += res;
        if(sum > w){
            cout<<-1<<endl;
            return 0;
        }
        ans[v[i].first] = res;
    }
    int rem = w - sum;
    for(int i = 0; i < v.size(); i++){
        int temp = min(rem, v[i].second - ans[v[i].first]);
        ans[v[i].first] += temp;
        rem -= temp;
        if(rem <= 0)
            break;
    }

    for(int i = 0; i < n; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}
