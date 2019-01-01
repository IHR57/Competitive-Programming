#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll arr[MAX], temp[MAX], n, s, low, high, mid, ans, idx;

    cin>>n>>s;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    low = 0, high = n;

    while(low <= high){
        mid = (low + high + 1) / 2;
        for(int i = 0; i < n; i++){
            temp[i] = arr[i] + ((i + 1) * mid);
        }

        sort(temp, temp + n);

        ll sum = 0;
        for(int i = 0; i < mid; i++){
            sum += temp[i];
        }
        if(sum <= s){
            idx = mid;
            ans = sum;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }

    cout<<idx<<" "<<ans<<endl;

    return 0;
}
