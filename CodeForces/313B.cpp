#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string str;
    int dp[MAX];

    cin>>str;

    dp[0] = 0;
    int len = (int) str.length();

    for(int i = 0; i < len; i++){
        if(str[i] == str[i+1]){
            dp[i+1] = dp[i] + 1;
        }
        else{
            dp[i+1] = dp[i];
        }
    }
    dp[len] = dp[len-1];

    int q, a, b;

    cin>>q;

    for(int i = 0; i < q; i++){
        cin>>a>>b;
        cout<<dp[b-1] - dp[a-1]<<endl;
    }

    return 0;
}
