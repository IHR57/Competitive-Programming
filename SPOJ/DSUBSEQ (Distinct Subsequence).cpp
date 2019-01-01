#include <bits/stdc++.h>
#define MAX 1000005
#define MOD 1000000007
using namespace std;

typedef long long ll;

ll dp[MAX], occur[200];
char str[MAX];

int main()
{
    int test;

    scanf("%d", &test);

    while(test--){
        scanf("%s", str+1);
        int len = strlen(str+1);
        memset(occur, 0, sizeof(occur));
        dp[0] = 1;
        for(int i = 1; i <= len; i++){
            dp[i] = (2 * dp[i-1] - dp[occur[str[i]] - 1] + MOD) % MOD;
            occur[str[i]] = i;
        }
        printf("%lld\n", dp[len] % MOD);
    }

    return 0;
}
