//Problem ID: CodeForces - 761C (Dasha and Password)
//Programmer: IQBAL HOSSAIN 	Description: Brute Force / DP
//Date: 23/07/19
//Contest: https://vjudge.net/contest/313461
#include <bits/stdc++.h>
#define MAX 100005
#define pb push_back
#define INF 2147483647
#define MOD 1000000007
using namespace std;

typedef long long ll;

int dp[55][3];
const int inf = 1<<28;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, m;
    string str;

    cin>>n>>m;

    for(int i = 0; i < n; i++){
    	dp[i][0] = dp[i][1] = dp[i][2] = inf;
    }
    for(int i = 0; i < n ; i++){
    	cin>>str;
    	for(int j = 0; j < m; j++){
    		if(str[j] >= 'a' && str[j] <= 'z'){
    			dp[i][0] = min(dp[i][0], min(j, m - j));
    		}
    		else if(str[j] >= '0' && str[j] <= '9'){
    			dp[i][1] = min(dp[i][1], min(j, m - j));
    		}
    		else{
    			dp[i][2] = min(dp[i][2], min(j, m - j));
    		}
    	}
    }

    int Min = 1e9;
    for(int i = 0; i < n; i++){
    	for(int j = i + 1; j < n ; j++){
    		for(int k = j + 1; k < n; k++){
    			Min = min(Min, dp[i][0] + dp[j][1] + dp[k][2]);
    			Min = min(Min, dp[i][0] + dp[j][2] + dp[k][1]);
    			Min = min(Min, dp[i][1] + dp[j][0] + dp[k][2]);
    			Min = min(Min, dp[i][1] + dp[j][2] + dp[k][0]);
    			Min = min(Min, dp[i][2] + dp[j][0] + dp[k][1]);
    			Min = min(Min, dp[i][2] + dp[j][1] + dp[k][0]);
    		}
    	}
    }

    cout<<Min<<endl;

    return 0;
}