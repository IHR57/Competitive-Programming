#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int arr[MAX];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, sum = 0, Min = 1e9;

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
        if(arr[i] > 0){
            sum += arr[i];
            if(arr[i] % 2){
                Min = min(Min, arr[i]);
            }
        }
        else{
            if((abs(arr[i])) % 2){
                Min = min(Min, abs(arr[i]));
            }
        }
    }

    if(sum % 2 == 0){
        sum -= Min;
    }

    cout<<sum<<endl;

    return 0;
}
