//Count of Numbers in Range where first digit is equal to last digit of the number
#include <bits/stdc++.h>
#define MAX 25
using namespace std;

typedef long long ll;

ll dp[MAX][MAX][MAX][2][2];
int visited[MAX][MAX][MAX][2][2], lim, cnt;
vector<int> digit;

ll solve(int pos, int firstD, int lastD, int isStart, int isSmall)
{
    if(pos == lim){
        if(firstD == lastD)
            return 1;
        return 0;
    }

    ll &ret = dp[pos][firstD][lastD][isStart][isSmall];
    int &v = visited[pos][firstD][lastD][isStart][isSmall];

    if(v == cnt)
        return ret;
    v = cnt;

    int last = (isSmall) ? 9 : digit[pos];

    ret = 0;

    if(!isStart){
        for(int i = 0; i <= last; i++){
            //if it is not starting position then firstD will remain constant
            ret += solve(pos + 1, firstD, i, 0, isSmall | i < digit[pos]);  
        }
    }
    else{
        for(int i = 1; i <= last; i++){
            ret += solve(pos + 1, i, i, 0, isSmall | i < digit[pos]);
        }
        ret += solve(pos + 1, digit[pos+1], digit[pos+1], 1, 1);
    }
    return ret;
}

ll cal(ll x)
{
    if(x <= 9){
        return x+1;
    }

    digit.clear();
    while(x){
        digit.push_back(x % 10);
        x /= 10;
    }
    cnt++;
    reverse(digit.begin(), digit.end());
    lim = digit.size();
    return solve(0, 0, 0, 1, 0);
}

int main()
{
    ll a, b;

    while(scanf("%lld %lld", &a, &b) == 2){
        ll result = cal(b) - cal(a - 1);
        printf("Result: %lld\n", result);
    }

    return 0;
}
