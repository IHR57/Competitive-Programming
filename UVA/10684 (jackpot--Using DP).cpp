#include <bits//stdc++.h>
using namespace std;

int main()
{
    int data[10005], n;

    while(scanf("%d", &n)){
        if(n==0)
            break;
        for(int i=0; i<n; i++){
            scanf("%d", &data[i]);
        }

        int dp[10005];
        memset(dp, 0, sizeof(dp));

        dp[0]=data[0];

        for(int i=1; i<n; i++){
            if(dp[i-1]+data[i]>data[i]){
                dp[i]=dp[i-1]+data[i];
            }
            else
                dp[i]=data[i];
        }

        int result = 0;

        for(int i=0; i<n; i++){
            result = max(result, dp[i]);
        }

        if(result==0)
            printf("Losing streak.\n");
        else
            printf("The winning streak is %d.\n", result);
    }

    return 0;
}
