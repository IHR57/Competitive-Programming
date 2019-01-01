#include <bits/stdc++.h>
#define MAX 500005
using namespace std;

typedef long long ll;

ll pos(ll n, ll m, ll mid)
{
    //cout<<"I am here"<<endl;
    ll sum = 0;
    mid--;
    for(int i = 1; i <= n; i++){
        sum += min(m, mid / i);
    }

    return sum;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, m, k, low, high, mid, ans;

    cin>>n>>m>>k;

    low = 1, high = n * m + 1;

    while(low < high){
        mid = (low + high) >> 1;
        if(pos(n, m, mid) < k){
            low = mid + 1;
        }
        else{
            high = mid;
        }
    }

    cout<<low - 1<<endl;

    return 0;
}
