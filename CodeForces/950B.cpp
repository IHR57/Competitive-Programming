#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, a[MAX], b[MAX];

    cin>>n>>m;

    for(int i = 0; i < n; i++){
        cin>>a[i];
    }

    for(int i = 0; i < m; i++){
        cin>>b[i];
    }

    int idx1 = 1, idx2 = 1, sum1 = 0, sum2 = 0, cnt = 0;

    sum1 = a[0], sum2 = b[0];

    while(true){
        if(sum1 == sum2)
            cnt++, sum1 = 0, sum2 = 0;
        if(idx1 >= n && idx2 >= m)
            break;
        //cout<<sum1<<" "<<sum2<<endl;
        if(sum1 <= sum2){
            sum1 += a[idx1], idx1++;
        }
        else{
            sum2 += b[idx2], idx2++;
        }
    }

    cout<<cnt<<endl;

    return 0;
}
