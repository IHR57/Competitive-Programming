//Problem ID: Hackerrank - Tower Breakers
//Programmer: IQBAL HOSSAIN     Description: Game Theory
//Date: 03/05/19
//Problem Link: https://www.hackerrank.com/challenges/tower-breakers-1/problem
#include <bits/stdc++.h>
#define MAX 1000005
using namespace std;

int main()
{
    int test, n, m;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d",  &n, &m);
        if(m == 1 || n % 2 == 0){
            printf("2\n");
        }
        else
            printf("1\n");
    }

    return 0;
}
