#include <bits/stdc++.h>
#define MAX 105
using namespace std;

const int inf = 1e9;

struct block{
    int a, b, c;

    block(int t1, int t2, int t3)
    {
        a = t1;
        b = t2;
        c = t3;
    }
};

vector<block> v;
int dp[MAX];

int solve(int i, int n)
{
    int Max = 0;

    if(dp[i] != -1)
        return dp[i];

    for(int j = 0; j < n; j++){
        if((v[j].a < v[i].a && v[j].b < v[i].b) || (v[j].a < v[i].b && v[j].b < v[i].a)){
            int ans = solve(j, n);
            if(ans > Max)
                Max = ans;
        }
    }

    dp[i] = Max + v[i].c;

    return dp[i];
}
int main()
{
    int n, caseNo = 1;
    int x, y, z;

    while(scanf("%d", &n) == 1){
        if(!n)  break;

        for(int i = 0; i < n; i++){
            scanf("%d %d %d", &x, &y, &z);
            v.push_back(block(x, y, z));
            v.push_back(block(y, z, x));
            v.push_back(block(z, x, y));
        }

        int result = 0;

        memset(dp, -1, sizeof(dp));

        for(int i = 0; i < 3 * n; i++){
            result = max(result, solve(i, 3 * n));
        }

        printf("Case %d: maximum height = %d\n", caseNo++, result);
        v.clear();
    }

    return 0;
}
