#include <bits/stdc++.h>
#define MAX 1005
using namespace std;

char ch[MAX][MAX];
int dp[MAX][MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;

    cin>>n>>m;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin>>ch[i][j];
            dp[i][j] = 1;
            if(ch[i][j] == ch[i-1][j]){
                dp[i][j] += dp[i-1][j];
            }
        }
    }
//
//    for(int i = 1; i <= n; i++){
//        for(int j = 1; j <= m; j++){
//            cout<<dp[i][j]<<" ";
//        }
//        cout<<endl;
//    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        int cnt = 0, tcnt = -1;
        for(int j = 1; j <= m; j++){
            int temp = dp[i][j];
            if(i >= (temp * 3) && (dp[i-temp][j] == dp[i][j]) && (dp[i-2*temp][j] >= dp[i][j]))
                temp = temp;
            else
                temp = 0;
            if(!temp)
                cnt = 0;
            else if(temp == tcnt && ch[i][j] == ch[i][j-1] && ch[i-temp][j] == ch[i-temp][j-1] && ch[i-2*temp][j] == ch[i-2*temp][j-1]){
                cnt++;
            }
            else
                cnt = 1;
            ans += cnt;
            tcnt = temp;

        }
    }

    cout<<ans<<endl;

    return 0;
}
