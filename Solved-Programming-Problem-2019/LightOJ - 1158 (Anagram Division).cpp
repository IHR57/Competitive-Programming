//Problem ID: LightOJ - 1158 (Anagram Division)
//Programmer: IQBAL HOSSAIN     Description: Dynamic Programming (BitMask)
//Date: 13/02/19
#include <bits/stdc++.h>
#define MAX 11
using namespace std;

typedef long long ll;

int dp[(1<<MAX)][1005];
vector<int> digit;
int n, d;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int solve(int mask, int rem)
{
	if(mask == (1<<n) - 1){
		if(rem == 0)
			return 1;
		return 0;
	}

	if(dp[mask][rem] != -1)
		return dp[mask][rem];

	int ret = 0;
	for(int i = 0; i < n; i++){
		if(!check(mask, i)){
			ret += solve(Set(mask, i), ((rem * 10) + digit[i]) % d);
		}
	}
	dp[mask][rem] = ret;

	return dp[mask][rem];
}

int main()
{
	int test, caseno = 1, counter[30], fact[15];
	char str[30];

    fact[0] = 1;
    for(int i = 1; i < 10; i++){
        fact[i] = i * fact[i-1];
    }

	scanf("%d",  &test);

	while(test--){
		scanf("%s %d", str, &d);
		n = strlen(str);

		digit.clear();
		memset(counter, 0, sizeof(counter));

		for(int i = 0; i < n; i++){
			digit.push_back(str[i] - 48);
            counter[str[i]-48]++;
		}

        memset(dp, -1, sizeof(dp));

		int result = solve(0, 0);

        for(int i = 0; i < 10; i++){        //we have to exclude duplicate permutation
            if(counter[i]){
                result /= fact[counter[i]];
            }
        }
		printf("Case %d: %d\n", caseno++, result);
	}

	return 0;
}
/*
3
000 1
1234567890 1
123434 2
*/
