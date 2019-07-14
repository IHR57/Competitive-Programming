//Problem ID: AtCoder - abc113_c (ID)
//Programmer: IQBAL HOSSAIN     Description: Sorting
//Date: 30/06/19
//Problem Link: https://atcoder.jp/contests/abc113/tasks/abc113_c
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef pair<int, int> pii;
vector<int> v[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt",  "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    int n, m, p,  y;
    vector<pii> vp;

    cin>>n>>m;

    for(int i = 0; i < m; i++){
        cin>>p>>y;
        v[p].push_back(y);
        vp.push_back(make_pair(p, y));
    }

    for(int i = 1; i <= n; i++){
        sort(v[i].begin(), v[i].end());
    }
    for(int i = 0; i < vp.size(); i++){
        int idx = lower_bound(v[vp[i].first].begin(), v[vp[i].first].end(), vp[i].second) - v[vp[i].first].begin();
        cout<<setw(6)<<setfill('0');
        cout<<vp[i].first;
        cout<<setw(6)<<setfill('0');
        cout<<(idx + 1)<<endl;
    }

    return 0;
}