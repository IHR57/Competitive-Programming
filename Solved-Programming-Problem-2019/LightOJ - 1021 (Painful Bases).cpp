//Problem ID: LightOJ - 1021 (Painful Bases)
//Programmer: IQBAL HOSSAIN     Description: Dynamic Programming (BitMask)
//Date: 17/01/19
#include <bits/stdc++.h>
#define MAX 22
using namespace std;

typedef long long ll;

ll dp[(1 << 16) + MAX][MAX];
int lim, base, k;
vector<int> digit;

ll solve(int mask, int rem)
{
    if(mask == ((1 << lim) - 1)){
        if(!rem)    return 1;
        return 0;
    }

    if(dp[mask][rem] != -1)
        return dp[mask][rem];

    ll ret = 0;
    for(int i = 0; i < lim; i++){
        if(!((mask >> i) & 1)){
            ret += solve((mask | (1 << i)), (rem * base + digit[i]) % k);
        }
    }

    dp[mask][rem] = ret;

    return dp[mask][rem];
}

int main()
{
    int test, caseno = 1;
    char str[MAX];

    scanf("%d", &test);

    while(test--){
        scanf("%d %d",  &base, &k);
        scanf("%s", str);

        int len = strlen(str);
        digit.clear();
        for(int i = 0; i < len; i++){
            if(str[i] >= 'A' && str[i] <= 'F'){
                digit.push_back(str[i] - 'A' + 10);
            }
            else{
                digit.push_back(str[i] - 48);
            }
        }
        lim = digit.size();

        memset(dp, -1, sizeof(dp));
        //cout<<sizeof(dp)<<endl;
        ll result = solve(0, 0);
        printf("Case %d: %lld\n", caseno++, result);
    }

    return 0;
}
