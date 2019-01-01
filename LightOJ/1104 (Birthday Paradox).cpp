#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int dp[505][5];

void precal()
{
    dp[0][0] = 1, dp[1][0] = 1, dp[1][1] = 1;

    for(int i = 2; i <= 500; i++){
        dp[i][0] = 1;
        for(int j = 1; j < 3; j++){
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }
}

int main()
{
    int test, caseNo = 1;
    double n;
    precal();

    scanf("%d", &test);

    while(test--){
        scanf("%lf", &n);
        int low = 1, high = 501, k = 1, ans;

        double result = 1.0;
        while(result > 0.5){
            result *= (1 - k / n);
            k++;
        }

        printf("Case %d: %d\n", caseNo++, k-1);
    }

    return 0;
}
