#include <bits/stdc++.h>
#define MAX 500005
using namespace std;

typedef long long ll;
int arr[MAX], counter[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;

    cin>>n;

    ll sum = 0;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
        sum += (ll) arr[i];
    }

    if(sum % 3 != 0){
        cout<<0<<endl;
    }
    else{
        ll part = sum / 3;
        ll temp  = 0;
        for(int i = n - 1; i >= 0; i--){
            temp += (ll) arr[i];
            if(temp == part){
                counter[i] = 1;
            }
        }

        for(int i = n - 2; i >= 0; i--){
            counter[i] += counter[i+1];
        }

        temp = 0;
        ll ans = 0;
        for(int i = 0; i + 2 < n; i++){
            temp += arr[i];
            if(temp == part){
                ans += counter[i+2];
            }
        }

        cout<<ans<<endl;
    }

    return 0;
}
