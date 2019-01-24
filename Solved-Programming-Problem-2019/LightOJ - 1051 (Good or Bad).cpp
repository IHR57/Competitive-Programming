//Problem ID: LightOJ - 1051 (Good or Bad)
//Programmer: IQBAL HOSSAIN     Description: Dynamic Programming
//Date: 24/01/19
//Problem Link: http://lightoj.com/volume_showproblem.php?problem=1051
#include <bits/stdc++.h>
#define MAX 55
#define read (freopen("input.txt", "r", stdin))
#define write (freopen("output.txt", "w", stdout))
using namespace std;

int dp[MAX][10][10];
bool isGood;
char str[MAX];
int len;

int solve(int pos, int vowel, int consonant, char lastChar)
{
    //cout<<pos<<" "<<vowel<<" "<<consonant<<" "<<lastChar<<endl;
    if(consonant == 5 || vowel == 3){
        isGood = false;
        return 1;
    }
    if(pos == len){
        return 2;
    }

    if(dp[pos][vowel][consonant] != -1)
        return dp[pos][vowel][consonant];

    if(str[pos] == '?'){
        int ans1 = solve(pos + 1, vowel + 1, 0, 'A');
        int ans2 = solve(pos + 1, 0, consonant + 1, 'B');
        dp[pos][vowel][consonant] = (ans1 | ans2);
    }
    else{
        if(str[pos] == 'A')
            dp[pos][vowel][consonant] = solve(pos + 1, vowel + 1, 0, str[pos]);
        else
            dp[pos][vowel][consonant] = solve(pos + 1, 0, consonant + 1, str[pos]);
    }

    return dp[pos][vowel][consonant];
}

int main()
{
    //read; write;
    int test, caseno = 1;

    scanf("%d", &test);

    while(test--){
        scanf("%s", str);
        len = strlen(str);

        for(int i = 0; i < len; i++){
            if(str[i] != '?'){
                if(str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U'){
                    str[i] = 'A';
                }
                else{
                    str[i] = 'B';
                }
            }
        }

        isGood = true;
        memset(dp, -1, sizeof(dp));
        int result = solve(0, 0, 0, '#');

        printf("Case %d: ", caseno++);
        if(result == 1){
            printf("BAD\n");
        }
        else if(result == 2){
            printf("GOOD\n");
        }
        else{
            printf("MIXED\n");
        }
    }

    return 0;
}
