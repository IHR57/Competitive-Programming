//Problem ID: HackerRank - Game of Stones
//Programmer: IQBAL HOSSAIN     Description: Game Theory
//Date: 03/05/19
//Problem Link: https://www.hackerrank.com/challenges/game-of-stones-1/problem
#include <bits/stdc++.h>
#define MAX 105
using namespace std;

bool canWin[MAX];

int main()
{
    int test, n;
    canWin[2] = canWin[3] = canWin[5] = 1;
    for(int i = 0; i < MAX; i++){
        if(!canWin[i]){
            if((i - 2 >= 0 && !canWin[i-2]) || (i - 3 >= 0 && !canWin[i-3]) || (i - 5 >= 0 && !canWin[i-5])){
                canWin[i] = 1;
            }
        }
    }
    scanf("%d",  &test);

    while(test--){
        scanf("%d", &n);
        (canWin[n]) ? printf("First\n") : printf("Second\n");
    }

    return 0;
}
