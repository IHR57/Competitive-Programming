#include <bits/stdc++.h>
#define MAX 100010
using namespace std;

typedef long long ll;

ll dp[MAX], arr[MAX];

int main()
{
    int test, n;

    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);
        memset(arr, 0, sizeof(arr));
        memset(dp, 0, sizeof(dp));

        for(int i = 0; i < n; i++){
            scanf("%lld", &arr[i]);
        }

        for(int i = n - 1; i >= 0; i--){
            dp[i] = max(arr[i] + dp[i+2], max(arr[i] + arr[i+1] + dp[i+4], arr[i] + arr[i+1] + arr[i+2] + dp[i+6]));
        }

        printf("%lld\n", dp[0]);
    }

    return 0;
}
