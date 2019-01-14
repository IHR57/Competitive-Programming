// print the sum of all the digits appearing in the integers between a and b
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

    while(scanf("%lld %lld", &a,  &b) == 2){
        ll result = cal(b) - cal(a - 1);

        printf("Result: %lld\n", result);
    }

    return 0;
}
