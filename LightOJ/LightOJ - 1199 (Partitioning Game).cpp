//Problem ID: LightOJ - 1199 (Partitioning Game)
//Programmer: IQBAL HOSSAIN     Description: Game Theory (Grundy Number)
//Date: 10/05/19
#include <bits/stdc++.h>
#define MAX 10005
#define MX 12
using namespace std;

int dp[MAX];

int solve(int n)
{
    if(n <= 2)
        return 0;
    if(dp[n] != -1)
        return dp[n];
    set<int> s;
    for(int i = 1; i < (n+1) / 2; i++){
        int h = solve(n - i);
        int g = solve(i);
        s.insert(g^h);
    }
    int k = 0;
    while(s.find(k) != s.end())
        k++;
    dp[n] = k;

    return dp[n];
}

int main()
{
    int test, caseno = 1, n;

    scanf("%d", &test);

    memset(dp, -1, sizeof(dp));

    while(test--){
        scanf("%d", &n);
        int val, res = 0;
        for(int i = 0; i < n; i++){
            scanf("%d", &val);
            res ^= solve(val);
        }
        printf("Case %d: ", caseno++);
        (res)  ? printf("Alice\n") : printf("Bob\n");
    }

    return 0;
}
