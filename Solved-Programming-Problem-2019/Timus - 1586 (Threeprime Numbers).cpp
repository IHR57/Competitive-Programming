//Problem ID: TIMUS - 1586 (ThreePrime Numbers)
//Programmer: IQBAL HOSSAIN     Description: Dynamic Programming
//Date: 19/07/19
#include <bits/stdc++.h>
#define MAX 2005
#define MOD 1000000009
using namespace std;

typedef long long ll;

bool mark[MAX];
vector<int> primes;
int dp[10005][1005], n;

int solve(int pos, int rem)
{
    if(pos >= n){
        return 1;
    }
    if(dp[pos][rem] != -1)
        return dp[pos][rem];
    int temp, ret = 0;
    temp = (rem * 10 + 1) % 1000;
    if(temp >= 100 && !mark[temp])
        ret = (ret + solve(pos + 1, temp)) % MOD;
    temp = (rem * 10 + 3) % 1000;
    if(temp >= 100 && !mark[temp])
        ret = (ret + solve(pos + 1, temp)) % MOD;
    temp = (rem * 10 + 7) % 1000;
    if(temp >= 100 && !mark[temp])
        ret = (ret + solve(pos + 1, temp)) % MOD;
    temp = (rem * 10 + 9) % 1000;
    if(temp >= 100 && !mark[temp])
        ret = (ret + solve(pos + 1, temp)) % MOD;

    return dp[pos][rem] = ret;
}

void genSieve()
{
    int limit = sqrt(MAX);
    mark[1] = 1;
    for(int i = 4; i < MAX; i += 2)
        mark[i] = 1;
    primes.push_back(2);

    for(int i = 3; i < MAX; i += 2){
        if(!mark[i]){
            primes.push_back(i);
            if(i <= limit){
                for(int j = i * i; j < MAX; j += i * 2)
                    mark[j] = 1;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt",  "w", stdout);
    #endif
    genSieve();

    cin>>n;
    memset(dp, -1, sizeof(dp));
    int res = 0;
    for(int i = 100; i < 1000; i++){
        if(!mark[i]){
            res = (res + solve(3, i)) % MOD;
        }
    }

    printf("%d\n", res);

    return 0;
}
