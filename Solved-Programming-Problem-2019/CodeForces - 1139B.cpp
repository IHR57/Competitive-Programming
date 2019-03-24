//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 200005
using namespace std;

typedef long long ll;

ll arr[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    ll sum = 0;
    sum += arr[n-1];

    for(int i = n - 2; i >= 0; i--){
        if(arr[i] > arr[i+1]){
            arr[i] -= (arr[i] - arr[i+1] + 1);
            if(arr[i] < 0)
                arr[i] = 0;
        }
        else if(arr[i] == arr[i+1]){
            if(arr[i] != 0)
                arr[i]--;
        }
        sum += arr[i];
    }

    cout<<sum<<endl;

    return 0;
}

