#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int mark[MAX] = {0}, distinct[MAX], arr[MAX], value, n, m;

    cin>>n>>m;

    int k = 1;
    for(int i = 1; i <= n; i++){
        cin>>arr[i];
    }
    for(int i = n; i >= 1; i--){
        if(!mark[arr[i]]){
            mark[arr[i]] = 1;
            distinct[i] = k++;
        }
        else{
            distinct[i] = distinct[i+1];
        }
    }

    int q;
    for(int i = 0; i < m; i++){
        cin>>q;
        cout<<distinct[q]<<endl;
    }

    return 0;
}
