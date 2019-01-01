#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main()
{
    int n, arr[MAX], sum = 0;

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    sum += arr[0] + n - 1 + n;

    for(int i = 1; i < n; i++){
        sum += fabs(arr[i] - arr[i-1]);
    }

    cout<<sum<<endl;

    return 0;
}
