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
    int n, x,  y;

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>x>>y;
        v.push_back(data{x, y});
    }

    sort(v.begin(), v.end(), compare);

    int cnt = 0, Max = v[0].b;

    for(int i = 1; i < v.size(); i++){
        if(v[i].b < Max)
            cnt++;
        else if(v[i].b > Max)
            Max = v[i].b;
    }

    cout<<cnt<<endl;

    return 0;
}
