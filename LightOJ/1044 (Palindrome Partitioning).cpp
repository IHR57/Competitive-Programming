#include <bits/stdc++.h>
#define MAX 1005
#define INF 1<<28
using namespace std;

char str[MAX];
int dp[MAX], isPalin[MAX][MAX], len;

bool palin(int i, int j)
{
    if(i >= j)
        return true;
    if(isPalin[i][j] != -1)
        return isPalin[i][j];

    return isPalin[i][j] = (str[i] == str[j]) && palin(i + 1, j - 1);
}

int solve(int i)
{
    if(i == len)
        return 0;
    if(dp[i] != -1)
        return dp[i];

    int Min = INF;

    for(int j = i; j < len; j++){
        if(palin(i, j)){
            Min = min(Min, 1 + solve(j + 1));
        }
    }
    dp[i] = Min;

    return dp[i];

}
int main()
{
    int test, caseno = 1;

    scanf("%d", &test);

    while(test--){
        scanf("%s", str);

        len = strlen(str);

        memset(isPalin, -1, sizeof(isPalin));
        memset(dp, -1, sizeof(dp));

        int result = solve(0);

        printf("Case %d: %d\n", caseno++, result);
    }

    return 0;
}
