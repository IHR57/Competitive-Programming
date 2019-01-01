#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

struct data
{
    int a, b;
};

bool compare(data A, data B)
{
    return A.a < B.a;
}

vector<data> v;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, d, cs[MAX], t[MAX];

    cin>>n>>d;

    for(int i = 0; i < n; i++){
        int x, y;
        cin>>x>>y;
        data temp;
        temp.a = x, temp.b = y;
        v.push_back(temp);
    }

    sort(v.begin(), v.end(), compare);

    cs[0] = 0;
    for(int i = 0; i < v.size(); i++){
        cs[i+1] = cs[i] + v[i].b;
    }

    for(int i = 0; i < v.size(); i++){
        t[i+1] = v[i].a;
    }

    ll Max = -1;

    for(int i = 1; i <= n; i++){
        int idx = upper_bound(t + 1, t + n + 1, t[i] + d - 1) - t;
        ll sum = cs[idx-1] - cs[i-1];
        //cout<<sum<<endl;
        if(sum > Max)
            Max = sum;
    }

    cout<<Max<<endl;

    return 0;
}
