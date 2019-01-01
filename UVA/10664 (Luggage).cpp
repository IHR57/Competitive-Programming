#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <cstdlib>
#define MAX 205
using namespace std;

int dp[MAX][MAX], cap, n, weight[MAX];

int solve(int i, int w)
{
    if(i == n){
        return 0;
    }
    if(dp[i][w] != -1)
        return dp[i][w];

    int profit1 = 0, profit2 = 0;

    if(w + weight[i] <= cap)
        profit1 = weight[i] + solve(i + 1, w + weight[i]);
    profit2 = solve(i + 1, w);

    dp[i][w] = max(profit1, profit2);

    return dp[i][w];
}

int main()
{
    int test;
    string line;

    scanf("%d", &test);
    getchar();

    while(test--){
        getline(cin, line);
        istringstream in(line);

        int i = 0, sum = 0;
        while(in>>weight[i]){
            sum += weight[i];
            i++;
        }
        n = i;

        if(sum % 2 != 0){
            printf("NO\n");
        }
        else{
            cap = sum / 2;
            memset(dp, -1, sizeof(dp));
            int result = solve(0, 0);
            //cout<<result<<endl;
            if(result == cap){
                printf("YES\n");
            }
            else{
                printf("NO\n");
            }
        }
    }

    return 0;
}
