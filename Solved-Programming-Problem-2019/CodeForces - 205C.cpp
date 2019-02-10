//Problem ID: CodeForces - 205C (Little Elephant and Interval)
//Programmer: IQBAL HOSSAIN     Description: DP
//Date: 06/02/19
//Problem Link: https://codeforces.com/contest/205/problem/C
#include <bits/stdc++.h>
#define MAX 20
using namespace std;

typedef long long ll;

ll dp[MAX][11][11][2][2];
int visited[MAX][11][11][2][2], cnt, lim;
vector<int> digits;

ll solve(int pos, int firstD, int lastD, int isSmall, int isStart)
{
    if(pos == lim){
        if(firstD == lastD)
            return 1;
        return 0;
    }

    ll &ret = dp[pos][firstD][lastD][isSmall][isStart];
    int &v = visited[pos][firstD][lastD][isSmall][isStart];

    if(v == cnt)
        return ret;

    v = cnt;
    int last = isSmall ? 9 : digits[pos];

    ret = 0;
    if(!isStart){
        for(int i = 0; i <= last; i++){
            ret += solve(pos + 1, firstD, i, isSmall | i < digits[pos], 0);
        }
    }
    else{
        for(int i = 1; i <= last; i++){
            ret += solve(pos + 1, i, i, isSmall | i < digits[pos], 0);
        }
        ret += solve(pos + 1, digits[pos+1], digits[pos+1], 1, 1);
    }

    return ret;
}

ll cal(ll x)
{
    if(x <= 9)
        return x + 1;
    digits.clear();
    while(x){
        digits.push_back(x % 10);
        x /= 10;
    }
    cnt++;
    lim = digits.size();
    reverse(digits.begin(), digits.end());

    return solve(0, 0, 0, 0, 1);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll l, r;

    cin>>l>>r;

    ll result = cal(r) - cal(l-1);

    cout<<result<<endl;

    return 0;
}
