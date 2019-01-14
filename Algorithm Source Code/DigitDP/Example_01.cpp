//Find number of zeroes in given range
//Source: http://shakilcompetitiveprogramming.blogspot.com/2015/09/digit-dp.html
//Problem: LightOJ - 1140 (How Many Zeroes) 
#include <bits/stdc++.h>
#define MAX 80
using namespace std;

typedef long long ll;

ll dp[2][2][MAX][MAX];
int visited[2][2][MAX][MAX];
int lim, cnt;
vector<int> digit;

/*
isSmall - This will tell if the current digits range is restricted or not. If the current digit’s
        range is not restricted then it will span from 0 to 9 (inclusively) else it will span
        from 0 to digit[pos] (inclusively).

value - This parameter will store the number of zero in the generated integer from 0 to pos

isStart - This is tell if the current digits is the starting digit or not. If it is starting digit
        then we cannot take zero at this position
*/
ll solve(int pos, int isSmall, int isStart, int value)
{
    if(pos == lim){
        return value;
    }
    ll &ret = dp[isSmall][isStart][pos][value];
    int &v = visited[isSmall][isStart][pos][value];
    if(v == cnt){
        return ret;
    }
    v = cnt;

    int last = isSmall ? 9 : digit[pos];
    ret = 0;

    if(!isStart){
        for(int i = 0; i <= last; i++){
            ret += solve(pos + 1, isSmall | i < digit[pos], 0, (i == 0) + value);
        }
    }
    else{
        for(int i = 1; i <= last; i++){
            ret += solve(pos + 1, isSmall | i < digit[pos], 0, (i == 0) + value);
        }
        ret += solve(pos + 1, 1, 1, 0);     //we need this call because leading zero is not allowed
    }

    return ret;
}

ll cal(ll x)
{
    if(x < 0)
        return 0;
    if(x <= 9)
        return 1;

    digit.clear();
    while(x){
        digit.push_back(x % 10);
        x /= 10;
    }

    reverse(digit.begin(), digit.end());
    lim = digit.size();
    cnt++;
    return solve(0, 0, 1, 0) + 1;
}

int main()
{
    int test, caseno = 1;
    ll n, m;

    scanf("%d", &test);

    while(test--){
        scanf("%lld %lld", &n, &m);
        ll result = cal(m) - cal(n - 1);
        printf("Case %d: %lld\n", caseno++, result);
    }

    return 0;
}
