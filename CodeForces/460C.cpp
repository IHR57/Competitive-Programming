// BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, w, arr[MAX];
    int low, high, mid;

    cin>>n>>m>>w;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    sort(arr, arr+n);

    int diff = arr[n-1] - arr[0];

    low = 1, high = m;

    while(low <= high){
        mid = (low + high + 1) >> 1;
        for(int i = 0; i < w; i++){
            arr[i] += mid;
        }
        sort(arr, arr + n);
        int temp = arr[n-1] - arr[0];
        if(temp > diff)
            low = mid + 1;
        else
            high = mid - 1;
    }

    cout<<arr[0]<<endl;

    return 0;
}
