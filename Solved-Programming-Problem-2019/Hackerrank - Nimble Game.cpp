//Problem ID: HackerRank - Nimble Game
//Programmer: IQBAL HOSSAIN     Description: Game Theory
//Date: 03/05/19
//Problem Link: https://www.hackerrank.com/challenges/nimble-game-1/problem
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main()
{
    int test, n;

    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);
        int ans = 0, val, sum = 0;
        for(int i = 0; i < n; i++){
            scanf("%d", &val);
            if(val % 2)
                ans ^= i;
        }

        (ans) ? printf("First\n") : printf("Second\n");
    }

    return 0;
}
