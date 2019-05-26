//Problem ID: AtCoder - dp_b (Frog 2)
//Programmer: IQBAL HOSSAIN     Description: Dynamic Programming
//Date: 25/05/19
//Problem Link: https://atcoder.jp/contests/dp/tasks/dp_b
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

const int inf = 2147483647;
int n, k, h[MAX], dp[MAX];

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    cin>>n>>k;

    for(int i = 0; i < n; i++){
        cin>>h[i];
    }
    dp[0] = 0;
    dp[1] = abs(h[0] - h[1]);
    for(int i = 2; i < n; i++){
        int x = min(i, k);
        dp[i] = inf;
        for(int j = 1; j <= x; j++){
            dp[i] = min(dp[i], dp[i-j] + abs(h[i] - h[i-j]));
        }
    }

    cout<<dp[n-1]<<endl;

    return 0;
}