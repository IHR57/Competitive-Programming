#include <bits/stdc++.h>
#define MAX 1000005
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int d, m, a[3000];

    cin>>d>>m;

    int sum = 0;

    for(int i = 0; i < m; i++){
        cin>>a[i];
        if(i >= 1){
            sum += d - a[i-1];
        }
    }

    cout<<sum<<endl;

    return 0;
}
