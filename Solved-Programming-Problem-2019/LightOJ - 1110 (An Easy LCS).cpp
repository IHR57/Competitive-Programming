//Problem ID: LightOJ - 1110 (An Easy LCS)
//Programmer: IQBAL HOSSAIN     Description: Dynamic Programming
//Date: 16/05/19
#include <bits/stdc++.h>
#define MAX 105
using namespace std;

string str1, str2;
int dp[MAX][MAX], n, m;
string res[MAX][MAX];

//int solve(int i, int j)
//{
//    if(i >= n || j >= m)
//        return 0;
//    if(dp[i][j] != -1)
//        return dp[i][j];
//    int ret = 0;
//    if(str1[i] == str2[j]){
//        ret = 1 + solve(i + 1, j + 1);
//    }
//    else{
//        ret = max(ret, solve(i + 1, j));
//        ret = max(ret, solve(i, j + 1));
//    }
//
//    return dp[i][j] = ret;
//}


int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int test, caseno = 1;
    cin>>test;

    while(test--){
        cin>>str1;
        cin>>str2;
        n = str1.size(), m = str2.size();
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i <= n; i++){
            dp[i][0] = 0;
            res[i][0] = "";
        }
        for(int j = 0; j <= m; j++){
            dp[0][j] = 0;
            res[0][j] = "";
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(str1[i-1] == str2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                    res[i][j] = res[i-1][j-1] + str1[i-1];
                }
                else{
                    if(dp[i-1][j] == dp[i][j-1]){
                        dp[i][j] = dp[i-1][j];
                        res[i][j] = min(res[i-1][j], res[i][j-1]);
                    }
                    else if(dp[i-1][j] > dp[i][j-1]){
                        dp[i][j] = dp[i-1][j];
                        res[i][j] = res[i-1][j];
                    }
                    else{
                        dp[i][j] = dp[i][j-1];
                        res[i][j] = res[i][j-1];
                    }
                }
            }
        }
        cout<<"Case "<<caseno++<<": ";
        (dp[n][m] == 0) ? cout<<":("<<endl : cout<<res[n][m]<<endl;
    }

    return 0;
}
