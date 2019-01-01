// BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 1005
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int arr[MAX], n;

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    sort(arr, arr + n);

    if(n % 2 != 0){
        cout<<arr[n/2]<<endl;
    }
    else{
        cout<<arr[n/2-1]<<endl;
    }

    return 0;
}
