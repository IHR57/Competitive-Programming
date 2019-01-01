#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#define MAX 10005
using namespace std;

int dp[MAX][2];

int main()
{
    int test, caseNo = 1, n, cap, song[55];

    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &n, &cap);

        memset(dp, 0, sizeof(dp));

        int sum = 0;
        for(int i = 1; i <= n; i++){
            scanf("%d", &song[i]);
            sum += song[i];
        }

        cap = min(cap-1, sum);
        //else{
            for(int i = 1; i <= n; i++){
                for(int j = cap; j >= song[i]; j--){
                    if(dp[j-song[i]][0] + 1 > dp[j][0]){
                        dp[j][0] = dp[j-song[i]][0] + 1;
                        dp[j][1] = dp[j-song[i]][1] + song[i];
                    }
                    if(dp[j-song[i]][0] + 1 == dp[j][0]){
                        dp[j][1] = max(dp[j][1], dp[j-song[i]][1] + song[i]);
                    }
                }
            }
            printf("Case %d: %d %d\n", caseNo++, dp[cap][0] + 1, dp[cap][1] + 678);
       // }
    }

    return 0;
}
