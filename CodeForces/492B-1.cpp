#include <bits/stdc++.h>
#define MAX 1005
#define EPS 1e-10
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, arr[MAX];
    double length;

    cin>>n>>length;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    sort(arr, arr+n);

    double low = 0.0, high = length + 1, left, ans, mid;

    for(int i = 1; i <= 100; i++){
        mid = (low + high) / 2.0;
        bool flag = false;
        left = 0.0;
        //cout<<low<<" "<<high<<endl;
        for(int j = 0; j < n; j++){
            double temp =  ((double)arr[j] - mid);
            if(temp > left){
                flag = true;
                break;
            }
            left = ((double)arr[j] + mid);
        }
        if(left < length){
            flag = true;
        }
        if(flag){
            low = mid + 1;
        }
        else{
            ans = mid;
            high = mid - 1;
        }
    }

    cout<<setiosflags(ios::fixed)<<setprecision(10);
    cout<<ans<<endl;

    return 0;
}
