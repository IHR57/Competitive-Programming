#include <bits/stdc++.h>
#define MAX 200005
using namespace std;

typedef pair<int, int> pii;
vector<pii> v;
bool compare(pii A, pii B)
{
    if(A.first == B.first)
        return A.second < B.second;
    return A.first < B.first;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, l, h;

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>l>>h;
        v.push_back(make_pair(l, h));
    }

    sort(v.begin(), v.end(), compare);

    int tv1l = -1, tv1r = -1, tv2l = -1, tv2r = -1;
    for(int i = 0; i < v.size(); i++){
        bool flag = false;
        if(v[i].first > tv1r){
            tv1l = v[i].first, tv1r = v[i].second;
            flag = true;
            continue;
        }
        if(v[i].first > tv2r){
            tv2l = v[i].first, tv2r = v[i].second;
            flag = true;
            continue;
        }
        if(!flag){
            cout<<"NO"<<endl;
            return 0;
        }
    }

    cout<<"YES"<<endl;

    return 0;
}
