//Problem ID: AtCoder - abc104_d (We Love ABC)
//Programmer: IQBAL HOSSAIN 	Description: Dynamic Programming
//Date: 01/08/19
//Problem Link: https://atcoder.jp/contests/abc104/tasks/abc104_d
#include <bits/stdc++.h>
#define MAX 100005
#define MOD 1000000007
using namespace std;

typedef long long ll;

ll dp[MAX][4];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	string str;

	cin>>str;

	dp[0][0] = 1;
	for(int i = 0; i < str.size(); i++){
		for(int j = 0; j < 4; j++){
			if(str[i] == '?')
				dp[i+1][j] = (dp[i+1][j] + (dp[i][j] * 3) % MOD) % MOD;
			else
				dp[i+1][j] = (dp[i+1][j] + dp[i][j]);
		}
		if(str[i] == 'A' || str[i] == '?')
			dp[i+1][1] = (dp[i+1][1] + dp[i][0]) % MOD;
		if(str[i] == 'B' || str[i] == '?')
			dp[i+1][2] = (dp[i+1][2] + dp[i][1]) % MOD;
		if(str[i] == 'C' || str[i] == '?')
			dp[i+1][3] = (dp[i+1][3] + dp[i][2]) % MOD;
	}

	cout<<dp[str.size()][3]<<endl;

	return 0;
}