#include <bits/stdc++.h>
#define MAX 2005
using namespace std;

int dp[MAX][MAX];

int main()
{
    int test;
    char first[MAX], second[MAX];

    scanf("%d", &test);

    while(test--){
        scanf("%s", first);
        scanf("%s", second);

        int len1 = strlen(first);
        int len2 = strlen(second);

        for(int i = 0; i <= len1; i++){
            for(int j = 0; j <= len2; j++){
                if(i == 0)
                    dp[i][j] = j;
                else if(j == 0)
                    dp[i][j] = i;
                else if(first[i-1] == second[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else{
                    dp[i][j] = 1 + min(min(dp[i][j-1], dp[i-1][j]), dp[i-1][j-1]);
                }
            }
        }

        printf("%d\n", dp[len1][len2]);
    }

    return 0;
}
