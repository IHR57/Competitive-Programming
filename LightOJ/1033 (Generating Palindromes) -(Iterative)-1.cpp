#include <bits/stdc++.h>
#define MAX 105
using namespace std;

int main()
{
    char str[MAX];
    int dp[MAX][MAX], test, caseNo = 1;

    scanf("%d", &test);

    while(test--){
        scanf("%s", str+1);
        int len = strlen(str+1);

        memset(dp, 0, sizeof(dp));

        for(int length = 1; length <= len; length++){
            for(int i = 1; i + length - 1 <= len; i++){
                int j = i + length - 1;
                if(str[i] == str[j]){
                    dp[i][j] = dp[i+1][j-1];
                }
                else{
                    dp[i][j] = min(dp[i+1][j], dp[i][j-1]) + 1;
                }
            }
        }
        printf("Case %d: %d\n", caseNo++, dp[1][len]);
    }

    return 0;
}
