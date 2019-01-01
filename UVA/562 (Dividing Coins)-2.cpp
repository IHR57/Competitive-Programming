#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cmath>
#define MAX 105
using namespace std;

int dp[50005];

int main()
{
    int test, coin[MAX], n, sum;

    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);

        sum = 0;
        for(int i = 0; i < n; i++){
            scanf("%d", &coin[i]);
            sum += coin[i];
        }

        memset(dp, 0, sizeof(dp));

        dp[0] = 1;
        for(int j = 0; j < n; j++){
            for(int i = sum; i >= 1; i--){
                if(i >= coin[j] && dp[i-coin[j]]){
                    dp[i] = 1;
                }
            }
        }

        int diff = 1<<28;
        for(int i = 0; i <= sum; i++){
            if(dp[i]){
                int temp = i - (sum - i);
                if(temp >= 0 && temp < diff)
                    diff = temp;
            }
        }

        printf("%d\n", diff);
    }

    return 0;
}
