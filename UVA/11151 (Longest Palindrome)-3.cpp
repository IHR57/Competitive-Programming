#include <iostream>
#include <cstdio>
#include <cstring>
#define MAX 1005
using namespace std;

int dp[MAX][MAX];
char str[MAX];

int solve(int l, int r)
{
    if(l == r)
        return 1;
    if(l + 1 == r){
        if(str[l] == str[r]){
            return 2;
        }
        else
            return 1;
    }
    if(dp[l][r] != -1){
        return dp[l][r];
    }

    if(str[l] == str[r]){
        return dp[l][r] = solve(l+1, r-1) + 2;
    }
    else{
        return dp[l][r] = max(solve(l, r - 1), solve(l + 1, r));
    }

}

int main()
{
    int test;

    scanf("%d", &test);
    getc(stdin);

    while(test--){
        gets(str);
        memset(dp, -1, sizeof(dp));

        int len = strlen(str);

        if(len == 0){
            printf("0\n");
            continue;
        }

        int ans = solve(0, len - 1);

        printf("%d\n", ans);
    }

    return 0;
}
