//Problem ID: HackerRank - Nikita and the Game
//Programmer: IQBAL HOSSAIN     Description: Recursion/DP
//Date: 19/05/19
//Problem Link: https://www.hackerrank.com/challenges/array-splitting/problem
#include <bits/stdc++.h>
#define MAX 20005
using namespace std;

typedef long long ll;
ll cs[MAX], arr[MAX];

int solve(int l, int r)
{
    ll leftSum = 0, rightSum = cs[r] - cs[l-1];

    if(rightSum == 0)
        return r - l;

    int res = 0;
    for(int i = l; i < r; i++){
        leftSum += arr[i];
        rightSum -= arr[i];
        if(leftSum == rightSum){
            res = 1 + max(solve(l, i), solve(i + 1, r));
            return res;
        }
    }
    return res;
}

int main()
{
    int test, n;

    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);
        cs[0] = 0;
        for(int i = 1; i <= n; i++){
            scanf("%lld", &arr[i]);
            cs[i] = arr[i] + cs[i-1];
        }

        int ans = solve(1, n);

        printf("%d\n", ans);
    }

    return 0;
}
