//Problem ID: HackerRank - Poker NIM
//Programmer: IQBAL HOSSAIN     Description: Game Theory
//Date: 04/05/19
//Problem Link: https://www.hackerrank.com/challenges/poker-nim-1/problem
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main()
{
    int test, n, k;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &n, &k);
        int ans = 0, val;
        for(int i = 0; i < n; i++){
            scanf("%d", &val);
            ans ^= val;
        }
        (ans) ? printf("First\n") : printf("Second\n");
    }

    return 0;
}
