#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll dp[MAX], counter[MAX] = {0};
    int maxi, value, n;

    cin>>n;

    maxi = -1;

    for(int i = 0; i < n; i++){
        cin>>value;
        counter[value]++;
        if(value > maxi)
            maxi = value;
    }

    dp[0] = 0, dp[1] = counter[1];
    for(int i = 2; i <= maxi; i++){
        dp[i] = max(dp[i-1], (ll) (dp[i-2] + (counter[i] * i)));
    }

    cout<<dp[maxi]<<endl;

    return 0;
}
