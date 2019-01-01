#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int dp[MAX];
char str[MAX];

int main()
{
    while(true){
        scanf("%s", str);
        if(str[0] == '0')
            break;
        dp[0] = dp[1] = 1;
        int len = strlen(str);

        for(int i = 2; i <= len; i++){
            dp[i] = 0;
            int v1 = str[i-2] - 48;
            int v2 = str[i-1] - 48;
            if(v1 == 1 || (v1 == 2 && v2 <= 6)){
                dp[i] += dp[i-2];
            }
            if(v2 != 0)
                dp[i] += dp[i-1];
        }

        printf("%d\n", dp[len]);
    }

    return 0;
}
