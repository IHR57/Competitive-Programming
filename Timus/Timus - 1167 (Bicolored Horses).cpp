//Problem ID: TIMUS - 1167 (Bicolored Horses)
//Programmer: IQBAL HOSSAIN 	Description: Dynamic Programming
//Date: 20/08/19
//Problem Link: http://acm.timus.ru/problem.aspx?space=1&num=1167
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define pi 3.1415926535897932384
#define INF 2147483647
#define MOD 1000000007
#define MAX 505
using namespace std;

typedef long long ll;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int dp[MAX][MAX];
int cs[MAX], n;

int solve(int pos, int k)
{
	if(k == 0){
		return ((n - pos) - (cs[n] - cs[pos])) * (cs[n] - cs[pos]);
	}
	if(dp[pos][k] != -1)
		return dp[pos][k];
	int ret = 2e9;
	for(int i = pos + 1; i <= n - k; i++){
		int temp = ((i - pos) - (cs[i] - cs[pos])) * (cs[i] - cs[pos]);
		ret = min(ret, temp + solve(i, k - 1));
	}
	
	return dp[pos][k] = ret;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int k;
    
    cin>>n>>k;
    
	int v;
	
	for(int i = 1; i <= n; i++){
		cin>>v;
		cs[i] = cs[i-1];
		if(v == 1)
			cs[i]++;
	}
	
	memset(dp, -1, sizeof(dp));
	int result = solve(0, k - 1);
	
	cout<<result<<endl;
}
