#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, t, low = 1, high, arr[MAX], cs[MAX];

    cin>>n>>t;

    cs[0] = 0;
    for(int i = 1; i <= n; i++){
        cin>>arr[i];
        cs[i] = cs[i-1] + arr[i];
    }

    int ans, result;

    high = n;
    while(low <= high){
        int mid = (low + high + 1) >> 1;
        int flag = 0;
        for(int i = 1; i <= n - mid + 1; i++){
            ans = cs[i+mid-1] - cs[i-1];
            if(ans <= t){
                flag = 1;
                break;
            }
        }
        if(flag){
            result = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }

    cout<<result<<endl;

    return 0;
}
