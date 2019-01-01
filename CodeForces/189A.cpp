#include <bits/stdc++.h>
#define MAX 4005
using namespace std;

int dp[MAX];
const int inf = 1<<28;
int a, b, c;

int solve(int n)
{
    if(n == 0)
        return 0;
    if(n < 0)
        return -inf;
    if(dp[n] != -1)
        return dp[n];
    int ans1 = solve(n - a) + 1;
    int ans2 = solve(n - b) + 1;
    int ans3 = solve(n - c) + 1;

    dp[n] = max(ans1, max(ans2, ans3));

    return dp[n];
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;

    cin>>n>>a>>b>>c;

    memset(dp, -1, sizeof(dp));
    int result = solve(n);

    cout<<result<<endl;

    return 0;
}
