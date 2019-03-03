// BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 200005
using namespace std;

typedef long long ll;

ll arr[MAX];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, s;

    cin>>n>>s;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    sort(arr, arr+n);

    ll sum = 0;
    int idx = n - 1;

    for(int i = 0; i < n; i++){
        if(arr[i] >= s){
            idx = i;
            break;
        }
    }

    int sum1 = 0, sum2 = 0;

    if(idx >= n / 2){
        for(int i = idx; i >= n / 2; i--){
            sum1 += (s - arr[i]);
        }
        cout<<sum1<<endl;
    }
    else{
        for(int i = idx; i <= n / 2; i++){
            sum2 += (arr[i] - s);
        }
        cout<<sum2<<endl;
    }

    //int ans = min(sum1, sum2);

    //cout<<ans<<endl;

    return 0;
}
