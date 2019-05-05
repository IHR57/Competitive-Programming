//Problem ID: HackerRank - A Chessboard Game
//Programmer: IQBAL HOSSAIN     Description: Game Theory
//Date: 03/05/19
//Problem Link: https://www.hackerrank.com/challenges/a-chessboard-game-1/problem
#include <bits/stdc++.h>
#define MAX 20
using namespace std;

bool solve(int i, int j)
{
    if(i < 1 || i > 15 || j < 1 || j > 15)
        return true;
    if(i <= 2 && j <= 2)
        return false;
    if(!solve(i-2, j + 1) || !solve(i-2, j-1) || !solve(i+1, j-2) || !solve(i-1, j-2))
        return true;
    return false;
}

int main()
{
    int test, x, y;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &x, &y);
        (solve(x, y)) ? printf("First\n") : printf("Second\n");
    }

    return 0;
}
