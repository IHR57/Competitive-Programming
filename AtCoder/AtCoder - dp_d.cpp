//Problem ID: AtCoder - dp_d (Knapsack 1)
//Programmer: IQBAL HOSSAIN     Description: Dynamic Programming
//Date: 27/05/19
//Problem Link: https://atcoder.jp/contests/dp/tasks/dp_d
#include <bits/stdc++.h>
#define MAX 105
using namespace std;

typedef long long ll;
const int inf = 2147483647;
int n, W, w[MAX], v[MAX];

ll dp[MAX][100005];

ll solve(int pos, int weight)
{
    if(pos >= n){
        return 0;
    }
    if(dp[pos][weight] != -1)
        return dp[pos][weight];
    ll ret = 0;
    if(weight + w[pos] <= W)
        ret = max(ret, v[pos] + solve(pos + 1, weight + w[pos]));
    ret = max(ret, solve(pos + 1, weight));

    return dp[pos][weight] = ret;
}

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    cin>>n>>W;

    for(int i = 0; i < n; i++){
        cin>>w[i]>>v[i];
    }

    memset(dp, -1, sizeof(dp));
    ll result = solve(0, 0);

    cout<<result<<endl;

    return 0;
}