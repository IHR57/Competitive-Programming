#include <bits/stdc++.h>
#define MAX 105
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k, arr[MAX];

    cin>>n>>k;

    int Min = 10000, Max = -10000;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
        if(arr[i] > Max)
            Max = arr[i];
        if(arr[i] < Min)
            Min = arr[i];
    }

    int diff = Max - Min;

    if(diff > k){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
        for(int i = 0; i < n; i++){
            for(int j = 1; j <= arr[i]; j++){
                if(j % k == 0){
                    cout<<k<<" ";
                }
                else{
                    cout<<j % k<<" ";
                }
            }
            cout<<endl;
        }
    }

    return 0;
}
