#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, arr[MAX];

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    ll e = 0;
    for(int i = n - 2; i >= 0; i--){
        if(arr[i] > arr[i+1]){
            e += (ll) (arr[i] - arr[i+1]);
        }
    }

    cout<<e<<endl;

    return 0;
}
