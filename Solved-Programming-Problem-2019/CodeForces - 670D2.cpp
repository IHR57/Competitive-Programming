//Problem ID: CodeForces - 670D2 (Magic Powder - 2)
//Programmer: IQBAL HOSSAIN     Description: Binary Search
//Date: 01/04/19
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

ll a[MAX], b[MAX], k;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;

    cin>>n>>k;

    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    for(int i = 0; i < n ; i++)
        cin>>b[i];

    ll low = 0, high = 2e9, mid, ans = -1;

    while(low <= high){
        ll temp, t = k;
        mid = (low + high + 1) >> 1;
        int flag = 1;
        for(int i = 0; i < n; i++){
            temp = mid * a[i];
            if(temp > b[i]){
                t -= (temp - b[i]);
                if(t < 0){
                    flag = 0;
                    break;
                }
            }
        }
        if(!flag){
            high = mid - 1;
        }
        else if(t >= 0){
            ans = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    if(ans == -1){
        cout<<0<<endl;
        return 0;
    }
    cout<<ans<<endl;

    return 0;
}
