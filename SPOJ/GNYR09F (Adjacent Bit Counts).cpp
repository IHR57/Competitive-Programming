#include <bits/stdc++.h>
#define MAX 105
using namespace std;

typedef long long ll;

ll dp[MAX][MAX];

int main()
{
    dp[1][0] = 2;
    dp[2][0] = 3, dp[2][1] = 1;

    for(int i = 3; i <= 100; i++){
        for(int j = 0; j < i; j++){
            if(j == 0){
                dp[i][j] = dp[i-1][j] + dp[i-2][j];
            }
            else{
                dp[i][j] = dp[i-1][j] + dp[i-1][j-1] + dp[i-2][j] - dp[i-2][j-1];
            }
        }
    }

    int test, serial, n, k;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d %d", &serial, &n, &k);
        printf("%d %lld\n", serial, dp[n][k]);
    }

    return 0;
}
