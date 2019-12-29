//Problem ID: LightOJ - 1084 (Winter)
//Programmer: IQBAL HOSSAIN     Description: Dynamic Programming
//Date: 02/04/19
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int dist[MAX], n, k, dp[MAX];
const int inf = 1<<28;
// int l[MAX], r[MAX];

int solve(int pos)
{
    if(pos >= n)
        return 0;
    if(dp[pos] != -1)
        return dp[pos];

    int idx = upper_bound(dist, dist + n, dist[pos] + (k * 2)) - dist;
    int ret1 = inf;

    if((idx - pos) >= 3)
        ret1 = min(ret1, 1 + solve(idx));
    if((idx - pos) >= 4)
        ret1 = min(ret1, 1 + solve(idx - 1));
    if((idx - pos) >= 5)
        ret1 = min(ret1, 1 + solve(idx - 2));

    return dp[pos] = ret1;
}

int main()
{
    int test, caseno = 1;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &n, &k);
        for(int i = 0; i < n; i++)
            scanf("%d",  &dist[i]);

        sort(dist, dist + n);

        // for(int i = 0; i < n; i++){
        //     int lidx = lower_bound(dist, dist + n, dist[i] - k) - dist;
        //     int ridx = upper_bound(dist, dist + n, dist[i] + k) - dist;
        //     l[i] = lidx;
        //     r[i] = ridx;
        // }

        memset(dp, -1, sizeof(dp));

        int result = solve(0);
        if(result == inf){
            printf("Case %d: -1\n", caseno++);
        }
        else
            printf("Case %d: %d\n", caseno++, result);
    }

    return 0;
}
