#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k, arr[MAX];

    cin>>n>>k;

    for(int i = 1; i <= n; i++){
        if(i <= k){
            arr[2*i-1] = 2 * i;
            arr[2*i] = 2 * i - 1;
        }
        else{
            arr[2*i-1] = 2 * i - 1;
            arr[2*i] = 2 * i;
        }
    }

    for(int i = 1; i <= 2 * n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}
