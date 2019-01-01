#include <bits/stdc++.h>
#define MAX 5005
using namespace std;

int dp[MAX][MAX], len1, len2;
char str[MAX], str1[MAX], str2[MAX];

int solve(int i, int j)
{
    if(i > len1 || j > len2)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];

    int ans = 0;
    if(str1[i] == str2[j]){
        ans = 1 + solve(i + 1, j + 1);
    }
    else{
        ans = max(solve(i + 1, j), solve(i, j + 1));
    }

    dp[i][j] = ans;
    return ans;
}

int main()
{
    int n;

    scanf("%d", &n);
    scanf("%s", str);

    int j = 0;

    memset(dp, -1, sizeof(dp));
    for(int i = n - 1; i >= n / 2; i--){
        str2[j++] = str[i];
    }

    j = 0;
    for(int i = 0; i < n / 2; i++)
        str1[j++] = str[i];

    //cout<<str1<<" "<<str2<<endl;
    len1 = n / 2, len2 = (n+1) / 2;

    int result = solve(0, 0);
    //cout<<result<<endl;

    if(n % 2 != 0 && result == max(len1, len2))
        printf("%d\n", 1);
    else
        printf("%d\n", (len1 - (result - 1)) * 2);

    return 0;
}
