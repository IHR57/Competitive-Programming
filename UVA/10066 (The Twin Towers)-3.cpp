#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAX 105
using namespace std;

int tower1[MAX], tower2[MAX];
int dp[MAX][MAX], visited[MAX][MAX];
int n1, n2;

int LCS(int i, int j)
{
    if(i >= n1 || j >= n2)      //base case
        return 0;
    int ans = 0;
    if(visited[i][j])
        return dp[i][j];

    if(tower1[i] == tower2[j])      //if two tiles are same
        ans = 1 + LCS(i + 1, j + 1);
    else{
        int value1 = LCS(i + 1, j);
        int value2 = LCS(i, j + 1);
        ans = max(value1, value2);
    }
    visited[i][j] = 1;      //mark them visited or calculated
    dp[i][j] = ans;

    return dp[i][j];
}

int main()
{
    int cases = 1;
    bool blank = false;

    while(scanf("%d %d", &n1, &n2) == 2){
        if(!n1 && !n2)
            break;

        for(int i = 0; i < n1; i++){
            scanf("%d", &tower1[i]);
        }
        for(int i = 0; i < n2; i++)
            scanf("%d", &tower2[i]);

        memset(dp, 0, sizeof(dp));      //initialize dp and visited array
        memset(visited, 0, sizeof(visited));

        int length = LCS(0, 0);

        printf("Twin Towers #%d\n", cases++);
        printf("Number of Tiles : %d\n\n", length);
    }

    return 0;
}
