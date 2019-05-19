//Problem ID: HackerRank - New Year Game
//Programmer: IQBAL HOSSAIN     Description: Game Theory
//Date: 14/05/19
//Problem Link: https://www.hackerrank.com/challenges/newyear-game/problem
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main()
{
    int test, n, val;

    scanf("%d",  &test);

    while(test--){
        scanf("%d", &n);
        int ans = 0;
        for(int i = 0; i < n; i++){
            scanf("%d",  &val);
            ans ^= (val % 3);
        }
        (ans) ? printf("Balsa\n") : printf("Koca\n");
    }

    return 0;
}
