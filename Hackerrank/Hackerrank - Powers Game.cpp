//Problem ID: HackerRank - Powers Game
//Programmer: IQBAL HOSSAIN     Description: Game Theory
//Date: 11/05/19
//Problem Link: https://www.hackerrank.com/challenges/powers-game-1/problem
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main()
{
    int test, n;

    scanf("%d", &test);

    while(test--){
        scanf("%d",  &n);
        (n % 8) ? printf("First\n") : printf("Second\n");
    }

    return 0;
}
