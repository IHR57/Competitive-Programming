//Problem ID: LightOJ - 1068 (Investigation)
//Programmer: IQBAL HOSSAIN     Description: Dynamic Programming
//Date: 14/01/19
#include <bits/stdc++.h>
#define read (freopen("input.txt", "r", stdin))
#define write (freopen("output.txt", "w", stdout))
#define MAX 105
using namespace std;

typedef long long ll;

ll dp[2][12][MAX][MAX];
int visited[2][12][MAX][MAX], lim, cnt, k;
vector<int> digit;

ll solve(int pos, int isSmall, int rem, int digitSum)
{
    if(pos == lim){
        if(!rem && !digitSum)
            return 1;
        return 0;
    }
    ll &ret = dp[isSmall][pos][rem][digitSum];
    int &v = visited[isSmall][pos][rem][digitSum];

    if(v == cnt)
        return ret;
    v = cnt;

    int last = (isSmall) ? 9 : digit[pos];
    ret = 0;

    for(int i = 0; i <= last; i++){
        ret += solve(pos + 1, isSmall | i < digit[pos], (rem * 10 + i) % k, (digitSum + i) % k);
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

    reverse(digit.begin(),digit.end());

    return solve(0, 0, 0, 0);
}

int main()
{
    //read; write;
    int test, caseno = 1;
    ll a, b;

    scanf("%d", &test);

    while(test--){
        scanf("%lld %lld %d", &a,  &b, &k);
        ll result;
        if(k > 81){
            result = 0;
        }
        else
            result = cal(b) - cal(a - 1);

        printf("Case %d: %lld\n", caseno++, result);
    }

    return 0;
}
