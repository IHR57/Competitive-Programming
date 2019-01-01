#include <bits/stdc++.h>
#define MAX 1005
using namespace std;

struct data
{
    int x, idx;
};

bool compare(data A, data B)
{
    return A.x > B.x;
}

vector<data> v;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, k, value;

    cin>>n>>k;

    for(int i = 0; i < n; i++){
        cin>>value;
        data temp;
        temp.x = value , temp.idx = i + 1;
        v.push_back(temp);
    }

    sort(v.begin(), v.end(), compare);

    int temp;

    for(int i = 0; i < k; i++){
        if(i == k - 1)
            temp = v[i].x;
    }

    cout<<temp<<endl;
    for(int i = 0; i < k; i++){
        cout<<v[i].idx<<" ";
    }
    cout<<endl;

    return 0;
}
