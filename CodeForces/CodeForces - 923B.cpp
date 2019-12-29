//Problem ID: CodeForces - 923B (Producing Snow)
//Programmer: IQBAL HOSSAIN     Description: Data Structures
//Date: 06/05/19
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int n;
int a[MAX], t[MAX], tree[MAX];
ll cs[MAX], m[MAX];

void update(int idx, int val)
{
    while(idx <= n){
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

int query(int idx)
{
    int sum = 0;
    while(idx > 0){
        sum += tree[idx];
        idx -= (idx & -idx);
    }

    return sum;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin>>n;

    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }
    for(int i = 1; i <= n; i++){
        cin>>t[i];
        cs[i] = cs[i-1] + (ll) t[i];
    }

    for(int i = 1; i <= n; i++){
        ll temp = cs[i-1] + a[i];
        int idx = lower_bound(cs, cs + n + 1, temp) - cs;
        if(idx >= i){
            update(i, 1);
            update(idx, -1);
            m[idx] += temp - cs[idx-1];
        }
    }

    for(int i = 1; i <= n; i++){
        ll ans = (query(i) * 1LL * t[i]) + m[i];
        cout<<ans<<" ";
    }
    cout<<endl;

    return 0;
}
