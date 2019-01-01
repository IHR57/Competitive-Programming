#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstdio>
using namespace std;

typedef unsigned long long int lint;

lint dp[35][35];

lint nCr(int n, int r)      //combination
{
    if(n == r)
        return 1;
    if(r == 1)
        return n;
    if(dp[n][r] != -1)
        return dp[n][r];
    else{
        dp[n][r] = nCr(n-1, r) + nCr(n-1, r-1);
        return dp[n][r];
    }
}

int main()
{
    for(int i = 0; i < 35; i++){
        for(int j = 0; j < 35; j++){
            dp[i][j] = -1;
        }
    }

    int n, k, test, cases = 1;
    lint result;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &n, &k);
        if(k > n)
            result = 0;
        else{
            lint temp = nCr(n, k);
            lint prod = 1;

            for(int i = 1; i <= k; i++){
                prod *= n;
                n--;
            }
            result = temp * prod;
        }

        printf("Case %d: %llu\n", cases++, result);
    }

    return 0;
}
