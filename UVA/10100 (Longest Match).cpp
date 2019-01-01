#include <iostream>
#include <cstdio>
#include <sstream>
#include <algorithm>
#include <string.h>
#define MAX 1005
using namespace std;

char strA[MAX], strB[MAX], temp[MAX];
string s1[MAX], s2[MAX];
int dp[MAX][MAX];
int visited[MAX][MAX], lenA, lenB, cases = 1;

int LCS()       //longest common subsequence -- tabulation technique
{
    memset(dp, 0, sizeof(dp));

    for(int i = 1; i <= lenA; i++){
        for(int j = 1; j <= lenB; j++){
            if(s1[i] == s2[j])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    printf("%2d. Length of longest match: %d\n", cases++, dp[lenA][lenB]);
}

void replaceChar(char* str)
{
    for(int i = 1; i <= strlen(str + 1); i++){
        if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'));
        else if(str[i] >= '0' && str[i] <= '9');
        else str[i] = ' ';
    }
}

int main()
{
    while(gets(strA + 1) != NULL){
        gets(strB + 1);

        if(strA[1] == 0 || strB[1] == 0){
            printf("%2d. Blank!\n", cases++);
            continue;
        }

        replaceChar(strA);
        replaceChar(strB);

        stringstream A(strA + 1);
        lenA = 0;
        while(A>>temp){
            s1[++lenA] = temp;
        }

        stringstream B(strB + 1);
        lenB = 0;
        while(B>>temp){
            s2[++lenB] = temp;
        }
        LCS();
    }

    return 0;
}
