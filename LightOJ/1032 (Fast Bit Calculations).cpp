#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int main()
{
    ll n, dp[50], N;
    int test, caseNo = 1;

    dp[0] = 0, dp[1] = 0, dp[2] = 1;
    for(int i = 3; i <= 32; i++){
        dp[i] = 2 * dp[i-1] + (1<<(i - 2));
    }

    //cout<<dp[4]<<" "<<dp[5]<<" "<<dp[6]<<endl;
    scanf("%d", &test);

    while(test--){
        scanf("%lld", &n);
        ll temp = n;
        int cnt = 0;
        while(temp != 0){
            cnt++;
            temp >>= 1;
        }
        ll ans = 0;
        for(int i = cnt - 1; i > 0 && n > 0; i--){
            if(n & (1<<i)){     //if i'th bit is set
                ll t = (1<<i) + (1<<(i - 1));
                if(t <= n){
                    ans += (n - t + 1);
                }
                ans += dp[i];
                //cout<<ans<<endl;
                n -= (1<<i);
                //cout<<n<<endl;
            }
        }

        printf("Case %d: %lld\n", caseNo++, ans);
    }

    return 0;
}
