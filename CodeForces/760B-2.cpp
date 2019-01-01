#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    ll n, m, left, right, sum, pos, temp;

    cin>>n>>m>>pos;

    ll low = 1, high = m, mid, ans;

    while(low <= high){
        mid = (low + high + 1) / 2;
        if((mid - 1) > (n - pos)){
            temp = (mid - 1) - (n - pos);
            right = ((mid * (mid - 1)) / 2) - ((temp * (temp + 1))/2);
        }
        else{
            temp = (n - pos) - (mid - 1);
            right = ((mid * (mid - 1)) / 2) + temp;
        }
        if((mid - 1) > (pos - 1)){
            temp = (mid - 1) - (pos - 1);
            left = ((mid * (mid - 1)) / 2) - ((temp * (temp + 1))/2);
        }
        else{
            temp = (pos - 1) - (mid - 1);
            left = ((mid * (mid - 1)) / 2) + temp;
        }
        //cout<<left<<" "<<right<<endl;
        sum = mid + left + right;       //total pillow required
        if(sum <= m)
            ans = mid;
        if(sum > m)
            high = mid - 1;
        else{
            low = mid + 1;
        }
    }

    cout<<ans<<endl;

    return 0;
}
