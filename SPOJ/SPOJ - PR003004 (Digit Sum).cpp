//Problem ID: SPOJ - PR003004 (Digit Sum)
//Programmer: IQBAL HOSSAIN     Description: Dynamic Programming, Digit-DP
//Date: 14/01/19
#include <bits/stdc++.h>
#define MAX 205
using namespace std;

typedef long long ll;

ll dp[2][20][MAX];
int visited[2][20][MAX], lim, cnt;
vector<int> digit;

ll solve(int pos, int isSmall, int sum)
{
    if(pos == lim){
        return sum;
    }

    ll &ret = dp[isSmall][pos][sum];
    int &v = visited[isSmall][pos][sum];

    if(v == cnt){
        return ret;
    }
    v = cnt;

    int last = (isSmall) ? 9 : digit[pos];
    ret = 0;

    for(int i = 0; i <= last; i++){
        ret += solve(pos + 1, isSmall | i < digit[pos], sum + i);
    }

    return ret;
}

ll cal(ll x)
{
    digit.clear();

    while(x){
        digit.push_back(x % 10);
        x /= 10;
    }

    cnt++;
    reverse(digit.begin(), digit.end());
    lim = digit.size();

    return solve(0, 0, 0);
}

int main()
{
    ll a, b;
    int test;

    scanf("%d", &test);

    while(test--){
        scanf("%lld %lld", &a, &b);
        ll result = cal(b) - cal(a - 1);
        printf("%lld\n", result);
    }
    return 0;
}
