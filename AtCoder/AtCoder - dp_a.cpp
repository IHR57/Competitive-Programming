//Problem ID: AtCoder - dp_a (Frog 1)
//Programmer: IQBAL HOSSAIN     Description: Dynamic Programming
//Date: 25/05/19
//Problem Link: https://atcoder.jp/contests/dp/tasks/dp_a
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

const int inf = 2147483647;
int n, h[MAX], dp[MAX];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    memset(dp, -1, sizeof(dp));
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>h[i];
    }

    dp[0] = 0;
    dp[1] = abs(h[1] - h[0]);

    for(int i = 2; i < n; i++){
        dp[i] = min((dp[i-1] + abs(h[i] - h[i-1])), (dp[i-2] + abs(h[i] - h[i-2])));
    }

    cout<<dp[n-1]<<endl;

    return 0;
}