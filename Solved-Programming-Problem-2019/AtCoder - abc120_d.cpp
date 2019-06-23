//Problem ID: AtCoder - abc120_d (Decayed Bridges)
//Programmer: IQBAL HOSSAIN     Descriptin: DSU
//Date: 03/06/19
//Problem Link: https://atcoder.jp/contests/abc120/tasks/abc120_d
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int parent[MAX], Size[MAX];
ll ans[MAX];
vector<pii> vp;

int findSet(int x)
{
    if(parent[x] == x)
        return x;
    return parent[x] = findSet(parent[x]);
}

bool isSameSet(int i, int j)
{
    return findSet(i) == findSet(j);
}

ll unionSet(int i, int j)
{
    if(!isSameSet(i, j)){
        int x = findSet(i);
        int y = findSet(j);
        ll a = (1LL * Size[x] * (Size[x] - 1)) / 2;
        ll b = (1LL * Size[y] * (Size[y] - 1)) / 2;
        ll c = Size[x] + Size[y];
        ll ans = ((1LL * c * (c - 1)) / 2) - a - b;
        //cout<<"Size: "<<a<<" "<<b<<" "<<c<<endl;
        if(Size[x] >= Size[y]){
            Size[x] += Size[y];
            parent[y] = x;
        }
        else{
            Size[y] += Size[x];
            parent[x] = y;
        }
        return ans;
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    int n, m, u, v;

    cin>>n>>m;

    for(int i = 1; i <= n; i++){
        parent[i] = i;
        Size[i] = 1;
    }

    for(int i = 0; i < m; i++){
        cin>>u>>v;
        vp.push_back(make_pair(u, v));
    }

    ans[m-1] = (1LL * n * (n - 1)) / 2;
    for(int i = vp.size() - 1; i >= 1; i--){
        if(isSameSet(vp[i].first, vp[i].second)){
            ans[i-1] = ans[i];
        }
        else{
            ans[i-1] = ans[i] - unionSet(vp[i].first, vp[i].second);
        }
    }

    for(int i = 0; i < m; i++){
        cout<<ans[i]<<endl;
    }

    return 0;
}