#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int a[MAX], dp[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin>>n;

    int ans = n;
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }

    dp[0] = 1;
    for(int i = 1; i < n; i++){
        dp[i] = 1;
        for(int j = 0; j < i; j++){
            if(a[i] >= a[j] && dp[i] < dp[j] + 1){
                dp[i] = dp[j] + 1;
            }
        }
    }

    cout<<*max_element(dp, dp + n)<<endl;

    return 0;
}
