#include <iostream>
#include <string.h>
#include <cstdio>
#include <algorithm>
#include <vector>
#define MAX 105
using namespace std;

char strA[MAX], strB[MAX];
int dp[MAX][MAX], visited[MAX][MAX];

int LCS(int i, int j)
{
    int ans = 0;
    if(strA[i] == '\0' || strB[j] == '\0')
        return 0;
    if(visited[i][j])
        return dp[i][j];        //if we calculate this before
    if(strA[i] == strB[j]){
        ans = 1 + LCS(i + 1, j + 1);
    }
    else{
        int value1 = LCS(i + 1, j);
        int value2 = LCS(i, j + 1);
        ans = max(value1, value2);
    }

    visited[i][j] = 1;      //make this visited
    dp[i][j] = ans;         //save the value

    return dp[i][j];        //return
}

int main()
{
    int cases = 1;

    while(cin.getline(strA, sizeof(strA))){
        if(strA[0] == '#')
            break;
        cin.getline(strB, sizeof(strB));

        memset(dp, 0, sizeof(dp));
        memset(visited, 0, sizeof(visited));

        int length = LCS(0, 0);     //longest common subsequence

        printf("Case #%d: you can visit at most %d cities.\n", cases++, length);
    }

    return 0;
}
