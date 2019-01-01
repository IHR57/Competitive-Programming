#include <bits/stdc++.h>
#define MAX 1005
using namespace std;

struct data
{
    int fst, snd;
};

bool compare(data A, data B)
{
    if(A.snd == B.snd)
        return A.fst > B.fst;
    return A.snd > B.snd;
}

vector<data> v;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, x, y;

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>x>>y;
        data temp;
        temp.fst = x, temp.snd = y;
        v.push_back(temp);
    }

    sort(v.begin(), v.end(), compare);

    int cnt = 1, sum = 0;

    for(int i = 0; i < v.size(); i++){
        cnt = cnt + v[i].snd - 1;
        sum += v[i].fst;
        if(cnt == 0)
            break;
    }

    cout<<sum<<endl;

    return 0;
}
