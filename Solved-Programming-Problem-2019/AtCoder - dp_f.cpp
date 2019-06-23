//Problem ID: AtCoder - dp_f (LCS)
//Programmer: IQBAL HOSSAIN     Description: Dynamic Programming
//Date: 28/05/19
//Problem Link: https://atcoder.jp/contests/dp/tasks/dp_f
#include <bits/stdc++.h>
#define MAX 3005
using namespace std;

typedef long long ll;

int dp[MAX][MAX], n, m;
string str1, str2;

int solve(int i, int j)
{
    if(i >= n || j >= m)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    int ret = 0;
    if(str1[i] == str2[j]){
        ret = 1 + solve(i + 1, j + 1);
    }
    else{
        ret = max(solve(i + 1, j), solve(i, j + 1));
    }
    return dp[i][j] = ret;
}

void printLCS(int i, int j)
{
    if(i >= n || j >= m)
        return;
    if(str1[i] == str2[j]){
        cout<<str1[i];
        printLCS(i + 1, j + 1);
    }
    else{
        if(dp[i+1][j] > dp[i][j+1]){
            printLCS(i + 1, j);
        }
        else{
            printLCS(i, j + 1);
        }
    }
}
int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    cin>>str1>>str2;    
    n = str1.size(), m = str2.size();
    memset(dp, -1, sizeof(dp));
    int res = solve(0, 0);
    //cout<<res<<endl;
    printLCS(0, 0);

    return 0;
}