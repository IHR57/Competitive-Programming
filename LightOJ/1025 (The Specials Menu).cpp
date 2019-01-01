#include <bits/stdc++.h>
#define MAX 65
using namespace std;

typedef long long ll;
char str[MAX];

ll dp[MAX][MAX];

ll solve(int i, int j)
{
    if(i > j)
        return 0;
    if(i == j)
        return 1;       //single character itself a palindrome
    if(dp[i][j] != -1)
        return dp[i][j];
    if(str[i] == str[j]){
        dp[i][j] = 1 + solve(i + 1, j) + solve(i, j - 1);
    }
    else{
        dp[i][j] = solve(i + 1, j) + solve(i, j - 1) - solve(i + 1, j - 1);     //we have to subtract because it is overlapped
    }

    return dp[i][j];
}

int main()
{
    int test, caseno = 1;

    scanf("%d", &test);

    while(test--){
        scanf("%s", str);
        int len = strlen(str);

        memset(dp, -1, sizeof(dp));

        ll result = solve(0, len-1);

        printf("Case %d: %lld\n", caseno++, result);
    }

    return 0;
}
