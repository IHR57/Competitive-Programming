//Problem ID: CodeForces - 401D
//Programmer: IQBAL HOSSAIN     Description: BitMaskDP
//Date: 20/01/19
//Problem Link: https://codeforces.com/contest/401/problem/D
#include <bits/stdc++.h>
#define MAX 18
using namespace std;

typedef long long ll;

ll dp[(1<<MAX)+10][105];
vector<int> digit;
int k, lim;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

ll solve(int mask, int rem)
{
    if(mask == (1 << lim) - 1){
        //cout<<t<<endl;
        if(!rem)
            return 1;
        return 0;
    }
    if(dp[mask][rem] != -1)
        return dp[mask][rem];

    ll ret = 0;
    int temp = 0;
    for(int i = 0; i < lim; i++){
        if(mask == 0 && digit[i] == 0)
            continue;
        if(!check(mask, i) && !check(temp, digit[i])){
            temp = Set(temp, digit[i]);
            ret += solve(Set(mask, i), (rem * 10 + digit[i]) % k);
        }
    }

    dp[mask][rem] = ret;

    return dp[mask][rem];
}

int main()
{
    ll n;
    scanf("%lld %d", &n, &k);

    digit.clear();
    while(n){
        digit.push_back(n % 10);
        n /= 10;
    }

    reverse(digit.begin(), digit.end());
    lim = digit.size();

    memset(dp, -1, sizeof(dp));

    ll result = solve(0, 0);

    printf("%lld\n", result);

    return 0;
}
