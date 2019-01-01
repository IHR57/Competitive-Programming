#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAX 1005
using namespace std;

char A[MAX], B[MAX];
int dp[MAX][MAX], visited[MAX][MAX];

int LCS(int i, int j)
{
    int ans = 0;
    if(A[i] == '\0' || B[j] == '\0')
        return 0;
    if(visited[i][j])
        return dp[i][j];
    if(A[i] == B[j]){
        ans = 1 + LCS(i + 1, j + 1);
    }
    else{
        int value1 = LCS(i + 1, j);
        int value2 = LCS(i, j + 1);
        ans = max(value1, value2);
    }

    visited[i][j] = 1;
    dp[i][j] = ans;

    return dp[i][j];        //return LCS
}

int main()
{
    while(cin.getline(A, sizeof(A))){
        cin.getline(B, sizeof(B));

        memset(dp, 0, sizeof(dp));
        memset(visited, 0, sizeof(visited));

        cout<<LCS(0, 0)<<endl;
    }

    return 0;
}
