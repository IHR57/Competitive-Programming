//Problem ID: LightOJ - 1315 (Game of Hyper Knights)
//Programmer: IQBAL HOSSAIN     Description: Game Theory (Grundy Numbers)
//Date: 11/05/19
#include <bits/stdc++.h>
#define MAX 505
using namespace std;

int dp[MAX][MAX*2];
int fx[] = { -2, -2, -1, +1, -3, -1 };
int fy[] = { +1, -1, -2, -2, -1, -3 };
const int inf = 10;

int solve(int i, int j)
{
    if(i < 0 || j < 0)
        return inf;
    if(dp[i][j] != -1)
        return dp[i][j];
    set<int> s;
    for(int k = 0; k < 6; k++){
        int g = solve(i + fx[k], j + fy[k]);
        s.insert(g);
    }

    int ret = 0;
    while(s.find(ret) != s.end())
        ret++;
    return dp[i][j] = ret;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int test, caseno = 1, x, y, n;

    scanf("%d",  &test);

    while(test--){
        scanf("%d", &n);
        int ans = 0;
        for(int i = 0; i < n; i++){
            scanf("%d %d", &x, &y);
            ans ^= solve(x, y);
        }
        printf("Case %d: ", caseno++);
        (ans) ? printf("Alice\n") : printf("Bob\n");
    }

    return 0;
}
