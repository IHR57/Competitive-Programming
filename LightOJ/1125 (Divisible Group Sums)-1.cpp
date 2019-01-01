#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;
int n, m, d;
ll arr[205], dp[205][22][11];

ll solve(int idx, int sum, int cnt)
{
    if(sum < 0)         //if negative
        sum += d;
    if(cnt == m){
        if(sum == 0)        //if it divisible by d
            return 1;
        else
            return 0;
    }
    if(idx > n)
        return 0;
    if(dp[idx][sum][cnt] != -1)
        return dp[idx][sum][cnt];
    ll ans =  0;
    ans += solve(idx + 1, (sum + arr[idx]) % d, cnt + 1);   //we will take this element
    ans += solve(idx + 1, sum % d, cnt);        //we will ignore this element

    dp[idx][sum][cnt] = ans;

    return dp[idx][sum][cnt];
}
int main()
{
    int test, caseno = 1, q;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &n, &q);
        for(int i = 1; i <= n; i++){
            scanf("%lld", &arr[i]);
        }

        printf("Case %d:\n", caseno++);

        while(q--){
            scanf("%d %d", &d, &m);
            memset(dp, -1, sizeof(dp));
            ll result = solve(1, 0, 0);

            printf("%lld\n", result);
        }
    }

    return 0;
}
