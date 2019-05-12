//Problem ID: HackerRank - Chocolate in Box
//Programmer: IQBAL HOSSAIN     Description: Game Theory
//Date: 09/05/19
//Problem Link: https://www.hackerrank.com/challenges/chocolate-in-box/problem
#include <bits/stdc++.h>
#define MAX 1000005
using namespace std;

int counter[35];

int main()
{
    int n, val;

    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &val);
        for(int j = 0; j <= 30; j++){
            if((val & (1 << j))){
                counter[j]++;
            }
        }
    }

    bool flag  = 0;
    for(int i = 30; i >= 0; i--){
        if(counter[i] % 2){
            printf("%d\n", counter[i]);
            flag = 1;
            break;
        }
    }
    if(!flag) printf("0\n");

    return 0;
}
