//Problem ID: UVA 10130 (Super Sale)
//Programmer: IQBAL HOSSAIN     Description: Dynamic Programming (0-1 Knapsack)
//Date: 08-10-16
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#define max(a, b) a>=b?a:b
#define MAX_N 1000
#define MAX_W 30
using namespace std;

int n, CAP;
int dp[MAX_N+1][MAX_W+1];
int weight[MAX_N+1];
int cost[MAX_N+1];

int func(int i, int w)      //function for 0-1 knapsack
{
    if(i==n+1)
        return 0;
    if(dp[i][w]!=-1)
        return dp[i][w];
    int profit1=0, profit2=0;

    if(w+weight[i]<=CAP){
        profit1=cost[i]+func(i+1, w+weight[i]);     //if we want to take this object
    }

    profit2=func(i+1, w);       //if we don't want to take this object

    dp[i][w]=max(profit1, profit2);     //take the maximum one

    return dp[i][w];
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int test, group, value, sum;

    cin>>test;

    while(test--){
        sum=0;
        scanf("%d", &n);

        for(int i=1; i<=n; i++){
            scanf("%d %d", &cost[i], &weight[i]);;
        }

        scanf("%d", &group);

        for(int i=1; i<=group; i++){
            memset(dp, -1, sizeof(dp));     //set all index of DP to -1
            scanf("%d", &CAP);
            value=func(1, 0);
            sum+=value;
        }
        printf("%d\n", sum);
    }

    return 0;
}

