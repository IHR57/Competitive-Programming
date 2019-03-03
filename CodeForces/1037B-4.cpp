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


    ll sum1 = 0, sum2 = 0;

    if(arr[n/2] == s){
        cout<<0<<endl;
    }
    else if(arr[n/2] < s){
        for(int i = n/2; i < n; i++){
            if(arr[i] < s)
                sum1 += (s - arr[i]);
        }
        cout<<sum1<<endl;
    }
    else{
        for(int i = n/2; i >= 0; i--){
            if(arr[i] > s)
                sum2 += (arr[i] - s);
        }
        cout<<sum2<<endl;
    }

    //int ans = min(sum1, sum2);

    //cout<<ans<<endl;

    return 0;
}
