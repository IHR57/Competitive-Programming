//Problem ID: AtCoder - dp_c (Vacation)
//Programmer: IQBAL HOSSAIN     Description: Dynamic Programming
//Date: 25/05/19
//Problem Link: https://atcoder.jp/contests/dp/tasks/dp_c
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

const int inf = 2147483647;
int n, k, dp[MAX][4], a[MAX], b[MAX], c[MAX];

int solve(int pos, int idx)
{
    if(pos >= n)
        return 0;
    if(dp[pos][idx] != -1)
        return dp[pos][idx];
    int ret = 0;
    if(idx == 0){
        ret = max(ret, a[pos] + solve(pos + 1, 1));
        ret = max(ret, a[pos] + solve(pos + 1, 2));
    }
    else if(idx == 1){
        ret = max(ret, b[pos] + solve(pos + 1, 0));
        ret = max(ret, b[pos] + solve(pos + 1, 2));
    }
    else{
        ret = max(ret, c[pos] + solve(pos + 1, 0));
        ret = max(ret, c[pos] + solve(pos + 1, 1));
    }

    return dp[pos][idx] = ret;
}

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>a[i]>>b[i]>>c[i];
    }

    memset(dp, -1, sizeof(dp));
    int result = max(solve(0, 0), max(solve(0, 1), solve(0, 2)));

    cout<<result<<endl;

    return 0;
}