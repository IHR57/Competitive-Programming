//Problem ID: CodeForces - 580D (Kefa and Dishes)
//Programmer: IQBAL HOSSAIN     Description: Dynamic Programming (Bitmask)
//Date: 22/01/19
//Problem Link: https://codeforces.com/contest/580/problem/D
#include <bits/stdc++.h>
#define MAX 18
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

ll dp[(1<<MAX) + 10][MAX+2];
int par[MAX+2][MAX+2], m, n, cost[MAX+2];
const int inf = 1<<28;

ll solve(int mask, int last)
{
    if(__builtin_popcount(mask) == m){
        return 0;
    }

    if(dp[mask][last] != -1)
        return dp[mask][last];

    ll ret = 0, Max = -inf;

    for(int i = 0; i < n; i++){
        if(!check(mask, i)){
            Max = max(Max, par[i][last] + cost[i] + solve(Set(mask, i), i));
        }
    }

    dp[mask][last] = Max;

    return dp[mask][last];
}

int main()
{
    int k;

    scanf("%d %d %d", &n, &m,  &k);

    for(int i = 0; i < n; i++){
        scanf("%d", &cost[i]);
    }

    for(int i = 0; i < k; i++){
        int x, y, c;
        scanf("%d %d %d", &x, &y, &c);
        par[y-1][x-1] = c;
    }

    memset(dp, -1, sizeof(dp));
    ll result = solve(0, 18);

    printf("%lld\n", result);

    return 0;
}
