#include <bits/stdc++.h>
#define MAX 10005
using namespace std;

typedef long long ll;

ll coin[MAX], dp[MAX];
int n;

ll solve(int i)
{
    if(i >= n)
        return 0;
    if(dp[i] != -1)
        return dp[i];

    ll ans1 = solve(i + 2) + coin[i];
    ll ans2 = solve(i + 1);

    dp[i] = max(ans1, ans2);

    return dp[i];
}

int main()
{
    int test, caseno = 1;

    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%lld", &coin[i]);
        }

        memset(dp, -1, sizeof(dp));

        ll result = solve(0);

        printf("Case %d: %lld\n", caseno++, result);
    }

    return 0;
}
