#include <bits/stdc++.h>
#define MAX 300005
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

    sort(arr, arr + n);

    ll sum = 0;

    int k = n - 1;
    for(int i = 0; i < n / 2; i++){
        sum += ((arr[i] + arr[k]) * (arr[i] + arr[k]));
        k--;
    }

    cout<<sum<<endl;

    return 0;
}
