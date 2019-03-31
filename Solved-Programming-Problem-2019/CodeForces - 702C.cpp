//Problem ID: CodeForces - 702C (Cellular Network)
//Programmer: IQBAL HOSSAIN     Description: Binary Search
//Date: 30/03/19
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int a[MAX], b[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;

    cin>>n>>m;

    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    for(int i = 0; i < m; i++){
        cin>>b[i];
    }

    int ans = -1;

    for(int i = 0; i < n; i++){
        int idx = lower_bound(b, b + m, a[i]) - b;
        if(idx == 0)
            ans = max(ans, b[0] - a[i]);
        else if(idx == m)
            ans = max(ans, a[i] - b[m-1]);
        else{
            ans = max(ans, min(abs(a[i] - b[idx]), abs(a[i] - b[idx-1])));
        }
    }

    cout<<ans<<endl;

    return 0;
}
