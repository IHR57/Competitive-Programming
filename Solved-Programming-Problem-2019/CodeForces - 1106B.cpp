#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

struct Data
{
    int idx, val;
};

bool compare(Data A, Data B)
{
    if(A.val == B.val)
        return A.idx < B.idx;
    return A.val < B.val;
}

vector<Data> vd;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int a[MAX], c[MAX], n, m, itemNo, tot;

    cin>>n>>m;

    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    for(int i = 0; i < n; i++){
        cin>>c[i];
        Data temp;
        temp.idx = i, temp.val = c[i];
        vd.push_back(temp);
    }

    sort(vd.begin(), vd.end(), compare);

    int k = 0;
    ll cost;
    for(int i = 0; i < m; i++){
        cost = 0;
        cin>>itemNo>>tot;
        itemNo--;
        if(tot <= a[itemNo]){
            a[itemNo] -= tot;
            cost += (ll) ((ll) tot * (ll) c[itemNo]);
            tot = 0;
        }
        else{
            int rem = a[itemNo];
            a[itemNo] = 0;
            cost += (ll) ((ll) rem * (ll) c[itemNo]);
            tot -= rem;
            for(int j = k; j < n && tot > 0; j++){
                rem = min(a[vd[j].idx], tot);
                tot -= rem;
                cost += (ll) ((ll) rem * (ll) c[vd[j].idx]);
                a[vd[j].idx] -= rem;
                if(a[vd[j].idx] == 0)
                    k++;
            }
        }
        if(tot > 0){
            cout<<0<<endl;
        }
        else{
            cout<<cost<<endl;
        }
    }

    return 0;
}
