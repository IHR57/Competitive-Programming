#include <bits/stdc++.h>
#define MAX 2005
using namespace std;

int dp[MAX][MAX];

int main()
{
    char str1[MAX], str2[MAX];
    int test, k;

    scanf("%s", str1);
    scanf("%s", str2);
    scanf("%d", &k);

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    for(int i = 0; i <= len1; i++)
        dp[i][0] = k * i;
    for(int i = 0; i <= len2; i++)
        dp[0][i] = k * i;

    for(int i = 1; i <= len1; i++){
        for(int j = 1; j <= len2; j++){
            int value = dp[i-1][j-1] + fabs((str1[i-1] - 'a') - (str2[j-1] - 'a'));
            dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]) + k, value);
        }
    }

    printf("%d\n", dp[len1][len2]);

    return 0;
}
