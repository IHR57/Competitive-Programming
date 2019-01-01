#include <bits/stdc++.h>
#define MAX 3005
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, arr[MAX];

    cin>>n>>m;

    for(int i = 0; i < m; i++){
        cin>>arr[i];
    }

    sort(arr, arr+m);

    if(arr[0] == 1 || arr[m-1] == n){
        cout<<"NO"<<endl;
    }
    else{
        for(int i = 0; i < m; i++){
            for(int j = i + 1; j < m; j++){
                if(arr[i] + 1 == arr[j] && arr[i] + 2 == arr[j+1]){
                    cout<<"NO"<<endl;
                    return 0;
                }
            }
        }
        cout<<"YES"<<endl;
    }

    return 0;
}
