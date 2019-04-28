#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int dp[2][MAX], arr[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;

    cin>>n>>m;

    int prev = 0;
    for(int i = 1; i <= n; i++){
        cin>>arr[i];
    }

    arr[0] = 0, arr[n+1] = m;

    for(int i = n; i >= 0; i--){
        dp[0][i] = dp[1][i+1];
        dp[1][i] = (arr[i+1] - arr[i]) + dp[0][i+1];
    }
    int Max = dp[1][0];

    for(int i = 0; i <= n; i++){
        if(arr[i+1] - arr[i] >= 2){
            int bt;
            if(i % 2 == 0)  bt = 1;
            else bt = 0;
            int temp = dp[1][0] - dp[bt][i];
            Max = max(Max, temp + (arr[i+1] - arr[i] - 1) + dp[bt][i+1]);
        }
    }

    cout<<Max<<endl;

    return 0;
}
