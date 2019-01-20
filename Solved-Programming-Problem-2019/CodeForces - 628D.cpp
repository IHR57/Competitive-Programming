//Problem ID: CodeForces - 628D (Magic Numbers)
//Programmer: IQBAL HOSSAIN     Description: DigitDP
//Date: 20/01/19
//Problem Link: https://codeforces.com/contest/628/problem/D
#include <bits/stdc++.h>
#define MAX 2005
#define MOD 1000000007
using namespace std;

typedef long long ll;

ll dp[MAX][MAX][2][2];
int visited[MAX][MAX][2][2];
int lim, m, d, cnt;
vector<int> digit;

ll solve(int pos, int rem, int isSmall, int isStart)
{
    if(pos == lim){
        if(!rem){
            return 1;
        }
        return 0;
    }

    ll &ret = dp[pos][rem][isSmall][isStart];
    int &v = visited[pos][rem][isSmall][isStart];

    if(v == cnt)
        return ret;
    v = cnt;

    int last = (isSmall) ? 9 : digit[pos];

    ret = 0;
    if(!isStart){
        for(int i = 0; i <= last; i++){
            if(pos % 2 == 0 && i == d){
                continue;
            }
            if(pos % 2 != 0 && i != d)
                continue;
            ret += solve(pos + 1, (rem * 10 + i) % m, isSmall | i < digit[pos], 0);
            ret %= MOD;
        }
    }
    else{
        for(int i = 1; i <= last; i++){
            if(pos % 2 == 0 && i == d){
                continue;
            }
            if(pos % 2 != 0 && i != d)
                continue;
            ret += solve(pos + 1, (rem * 10 + i) % m, isSmall | i < digit[pos], 0);
            ret %= MOD;
        }
    }

    return ret % MOD;
}

ll cal(char x[])
{
    digit.clear();

    lim  = strlen(x);
    for(int i = 0; i < lim; i++){
        digit.push_back(x[i] - 48);
    }

    cnt++;
    return solve(0, 0, 0, 1);
}

int main()
{
    char strA[MAX], strB[MAX];
    scanf("%d %d", &m, &d);
    scanf("%s", strA);
    scanf("%s", strB);

    //memset(dp, -1, sizeof(dp));

    ll result = cal(strB) - cal(strA);
    if(result < 0)
        result += MOD;

    int flag = 0, rem = 0;
    for(int i = 0; i < lim; i++){
        if(i % 2 == 0 && digit[i] == d){
            flag = 1;
            break;
        }
        if(i % 2 != 0 && digit[i] != d){
            flag = 1;
            break;
        }
        rem = (rem * 10 + digit[i]) % m;
    }

    if(!flag && !rem)
        result = (result + 1) % MOD;

    printf("%lld\n", result);

    return 0;
}
