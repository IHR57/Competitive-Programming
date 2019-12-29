//Problem ID: AtCoder - dp_e (Knapsack 2)
//Programmer: IQBAL HOSSAIN     Description: Dynamic Programming
//Date: 28/05/19
//Problem Link: https://atcoder.jp/contests/dp/tasks/dp_e
#include <bits/stdc++.h>
#define MAX 105
using namespace std;

typedef long long ll;

ll dp[MAX][100005];
const ll inf = 1e14;

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    int n, s = 0, W, w[MAX], v[MAX];

    cin>>n>>W;
    for(int i = 0; i < n; i++){
        cin>>w[i]>>v[i];
        s += v[i];
    }

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= s; j++)
            dp[i][j] = inf;
    }
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= s; j++){
            if(j < v[i-1])
                dp[i][j] = dp[i-1][j];
            else{
                dp[i][j] = min(dp[i-1][j] , w[i-1] + dp[i-1][j-v[i-1]]);
            }
        }
    }
    for(int i = s; i > 0; i--){
        if(dp[n][i] <= W){
            cout<<i<<endl;
            return 0;
        }
    }

    cout<<0<<endl;

    return 0;
}