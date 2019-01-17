//Problem ID: SPOJ - KOPC12H (K12-OE Numbers)
//Programmer: IQBAL HOSSAIN     Description: Dynamic Programming (Digit-DP)
//Date: 17/01/19
#include <bits/stdc++.h>
#define MAX 165
using namespace std;
typedef long long ll;

ll dp[19][MAX][MAX][2];
int visited[19][MAX][MAX][2], lim, cnt;
vector<int> digit;

ll solve(int pos, int oddSum, int evenSum, int isSmall)
{
    if(pos == lim){
        if(evenSum > oddSum)
            return 1;
        return 0;
    }

    ll &ret = dp[pos][oddSum][evenSum][isSmall];
    int &v = visited[pos][oddSum][evenSum][isSmall];

    if(v == cnt)
        return ret;
    v = cnt;

    int last = (isSmall) ? 9 : digit[pos];

    ret = 0;
    for(int i = 0; i <= last; i++){
        ret += solve(pos + 1, ((i % 2) != 0) ? oddSum + i : oddSum, ((i % 2) == 0) ? evenSum + i : evenSum, isSmall | i < digit[pos]);
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
    lim = digit.size();
    reverse(digit.begin(), digit.end());

    return solve(0, 0, 0, 0);
}

int main()
{
    int test;
    ll a, b;

    scanf("%d", &test);

    while(test--){
        scanf("%lld %lld", &a, &b);
        ll result = cal(b) - cal(a-1);
        printf("%lld\n", result);
    }

    return 0;
}
