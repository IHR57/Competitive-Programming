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

    for(int i = 0; i < 2 * n; i++){
        cin>>arr[i];
    }

    sort(arr, arr + 2 * n);

    ll result = (arr[n-1] - arr[0]) * (arr[2*n-1] - arr[n]);

    for(int i = 1; i < n; i++){
        result = min(result, (arr[2*n-1] - arr[0]) * (arr[i+n-1] - arr[i]));
    }

    cout<<result<<endl;

    return 0;

}
