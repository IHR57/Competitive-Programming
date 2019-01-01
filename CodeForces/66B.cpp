#include <bits/stdc++.h>
#define MAX 1005
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int arr[MAX], mx = -1, n;

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    for(int i = 0; i < n; i++){
        int left = 0, right = 0;
        for(int j = i - 1; j >= 0; j--){
            if(arr[j] <= arr[j+1])
                left++;
            else
                break;
        }

        for(int j = i + 1; j < n; j++){
            if(arr[j] <= arr[j-1])
                right++;
            else break;
        }

        int ans = left + right + 1;
        //cout<<ans<<endl;
        if(ans > mx)
            mx = ans;
    }

    cout<<mx<<endl;

    return 0;
}
