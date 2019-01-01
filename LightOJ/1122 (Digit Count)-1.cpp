#include <bits/stdc++.h>
#define MAX 105
using namespace std;

int n, k, arr[MAX], dp[MAX][MAX];

int solve(int pos, int len)
{
    if(len == k - 1)
        return 1;
    if(dp[pos][len] == -1){
        int sum = 0;
        for(int i = 0; i < n; i++){
            if(fabs(arr[pos] - arr[i]) <= 2){
                sum += solve(i, len + 1);
            }
        }
        dp[pos][len] = sum;
    }

    return dp[pos][len];
}

int main()
{
    int test, caseNo = 1;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &n, &k);

        for(int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
        }

        memset(dp, -1, sizeof(dp));

        int cnt = 0;
        for(int i = 0; i < n; i++){
            cnt += solve(i, 0);
        }

        printf("Case %d: %d\n", caseNo++, cnt);
    }

    return 0;
}

