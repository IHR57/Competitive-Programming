//Problem ID: LightOJ - 1283 (Shelving Books)
//Programmer: IQBAL HOSSAIN     Description: Dynamic Programming
//Date: 21/02/19
//Problem Link: http://lightoj.com/volume_showproblem.php?problem=1283
#include <bits/stdc++.h>
#define MAX 105
using namespace std;

int arr[MAX], n;
int dp[MAX][MAX][MAX];

const int inf = 1<<29;

int solve(int pos, int leftIdx, int rightIdx)
{
    if(pos >= n + 1){
        return 0;
    }
    if(dp[pos][leftIdx][rightIdx] != -1)
        return dp[pos][leftIdx][rightIdx];

    int ret = 0;

    if(arr[pos] >= arr[leftIdx] && arr[pos] <= arr[rightIdx]){
        ret = max(ret, 1 + solve(pos + 1, pos, rightIdx));      //taking the book and set current book to the left
        ret = max(ret, 1 + solve(pos + 1, leftIdx, pos));       //taking the book and set current book to the right
    }

    ret = max(ret, solve(pos + 1, leftIdx, rightIdx));          //ignore the book

    dp[pos][leftIdx][rightIdx] = ret;

    return dp[pos][leftIdx][rightIdx];
}

int main()
{
    int test, caseno = 1;

    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%d", &arr[i]);
        }

        memset(dp, -1, sizeof(dp));
        arr[n+1] = inf;
        int result = solve(1, 0, n+1);

        printf("Case %d: %d\n", caseno++, result);
    }

    return 0;
}
