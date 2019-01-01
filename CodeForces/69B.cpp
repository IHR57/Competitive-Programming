#include <bits/stdc++.h>
#define MAX 105
using namespace std;

struct data
{
    int l, r, t, d, idx;
};

bool compare(data A, data B)
{
    if(A.t == B.t)
        return A.idx < B.idx;
    return A.t < B.t;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    data a[MAX];
    int n, m, visited[MAX];

    cin>>n>>m;

    for(int i = 0; i < m; i++){
        cin>>a[i].l>>a[i].r>>a[i].t>>a[i].d;
        a[i].idx = i;
    }

    sort(a, a + m, compare);

    memset(visited, 0, sizeof(visited));

    for(int i = 0; i < m; i++){
        for(int j = a[i].l - 1; j < a[i].r; j++){
            if(!visited[j]){
                visited[j] = a[i].d;
            }
        }
    }

    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += visited[i];
    }

    cout<<sum<<endl;

    return 0;
}
