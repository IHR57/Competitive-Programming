//Problem ID: CodeForces - 976C (Nested Segments)
//Programmer: IQBAL HOSSAIN     Description: Sorting
//Date: 24/02/19
#include <bits/stdc++.h>
#define MAX 300005
using namespace std;

struct data{
    int l, r, idx;
};

bool compare(data A, data B)
{
    if(A.l == B.l){
        return A.r < B.r;
    }
    return A.l > B.l;
}

vector<data> v;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, x, y;

    cin>>n;

    for(int i = 0; i < n ; i++){
        cin>>x>>y;
        data temp;
        temp.idx = i, temp.l = x, temp.r = y;
        v.push_back(temp);
    }

    sort(v.begin(), v.end(), compare);

    for(int i = 1; i < n; i++){
        if(v[i].l <= v[i-1].l && v[i].r >= v[i-1].r){
            cout<<v[i-1].idx + 1<<" "<<v[i].idx + 1<<endl;
            return 0;
        }
    }
    cout<<-1<<" "<<-1<<endl;

    return 0;
}
