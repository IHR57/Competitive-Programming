#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

char str[50];
int dp[25][260], len;

int solve(int pos, int res)
{
    if(pos == len)
        return 1;
    int &ret = dp[pos][res];
    if(ret != -1)
        return ret;
    ret = 0;
    int sum = 0;
    for(int i = pos; i < len; i++){
        sum += str[i] - 48;
        if(sum >= res){
            int ans = solve(i + 1, sum);
            ret += ans;
        }
    }

    return ret;
}

int main()
{
    int caseno = 1;
    while(scanf("%s", str) != EOF){
        if(strcmp(str, "bye") == 0){
            break;
        }

        len = strlen(str);
        memset(dp, -1, sizeof(dp));

        int result = solve(0, 0);

        printf("%d. %d\n", caseno++, result);
    }

    return 0;
}
