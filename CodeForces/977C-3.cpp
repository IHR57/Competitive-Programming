// BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int arr[2*MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;

    cin>>n>>k;

    for(int i = 1; i <= n; i++){
        cin>>arr[i];
    }

    sort(arr + 1, arr + n + 1);

    if(k == 0 && n >= 2){
        if(arr[1] == 1 && arr[1] == 1){
            cout<<-1<<endl;
        }
        else{
            cout<<1<<endl;
        }
        return 0;
    }
    if(k == 0 && n == 1){
        if(arr[1] == 1)
            cout<<-1<<endl;
        else
            cout<<1<<endl;

        return 0;
    }

    if(arr[k] == arr[k+1])
        cout<<-1<<endl;
    else{
        cout<<arr[k]<<endl;
    }

    return 0;
}
