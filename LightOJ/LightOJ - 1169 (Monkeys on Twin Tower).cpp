//Problem ID: LightOJ - 1169 (Monkeys on Twin Tower)
//Programmer: IQBAL HOSSAIN     Description: Dynamic Programming
//Date: 14/02/19
#include <bits/stdc++.h>
#define MAX 1005
using namespace std;

int dp[3][MAX];
int cost1[MAX], cost2[MAX], tym1[MAX], tym2[MAX], n;

int solve(int tower, int pos)
{
	if(pos == n){
		return 0;
	}
	if(dp[tower][pos] != -1)
		return dp[tower][pos];

	int p1, p2;
	if(tower == 0){
		p1 = cost1[pos] + solve(tower, pos + 1);
		p2 = cost1[pos] + tym1[pos] + solve(!tower, pos + 1);
	}
	else if(tower == 1){
		p1 = cost2[pos] + solve(tower, pos + 1);
		p2 = cost2[pos] + tym2[pos] + solve(!tower, pos + 1);
	}

	dp[tower][pos] = min(p1, p2);

	return dp[tower][pos];
}

int main()
{
	int test, caseno = 1;

	scanf("%d", &test);

	while(test--){
		scanf("%d",  &n);
		for(int i = 0; i < n; i++){
			scanf("%d", &cost1[i]);
		}
		for(int i = 0; i < n; i++){
			scanf("%d", &cost2[i]);
		}
		for(int i = 0; i < n - 1; i++){
			scanf("%d", &tym1[i]);
		}
		for(int i = 0; i < n - 1; i++){
			scanf("%d", &tym2[i]);
		}

        tym1[n-1] = tym2[n-1] = 0;
		memset(dp, -1, sizeof(dp));

		int result = min(solve(0, 0), solve(1, 0));

		printf("Case %d: %d\n", caseno++, result);
	}

	return 0;
}
