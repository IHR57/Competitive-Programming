//Problem ID: LightOJ - 1145 (Dice I)
//Programmer: IQBAL HOSSAIN     Description: Dynamic Programming
//Date: 08/04/19
#include <bits/stdc++.h>
#define MAX 15005
#define MOD 100000007
using namespace std;

typedef long long ll;
int dp[MAX], cs[2][MAX];

// void bruteForce()
// {
//     int cnt = 0;
//     for(int i = 1; i <= 6; i++){
//         for(int j = 1; j <= 6; j++){
//             for(int k = 1; k <= 6; k++){
//                 //for(int l = 0; l <= 10; l++){
//                     if(i + j + k  == 11){
//                         //cout<<i<<" "<<j<<" "<<k<<" "<<l<<endl;
//                         cnt++;
//                     }
//                 //}
//             }
//         }
//     }

//     cout<<cnt<<endl;
// }

// ll bigMod(ll a, ll b)
// {
//     if(b == 0)
//         return 1;
//     ll x = bigMod(a, b / 2);
//     x = (x * x) % MOD;
//     if(b % 2 == 1)
//         x = (x * a) % MOD;
//     return x;
// }

// ll nCr(int n, int k)
// {
//     return ((fact[n] * bigMod(fact[k], MOD - 2)) % MOD * bigMod(fact[n-k], MOD - 2)) % MOD;
// }

int main()
{
    int test, n, k, s, caseno = 1;
    scanf("%d",  &test);

    while(test--){
        scanf("%d %d %d", &n, &k, &s);
        memset(dp, 0, sizeof(dp));
        memset(cs, 0, sizeof(cs));
        ll ans = 0;
        int temp = 1;
        for(int i = 1; i <= k; i++)
            dp[i] = 1, cs[1][i] = temp++;
        temp = k - 1;
        for(int i = k + 1; i <= 2 * k - 1; i++)
            cs[1][i] = temp--;

        int f;
        for(int i = 2; i <= n; i++){
            ll sum = 0;
            queue<int> q;
            (i % 2 == 0) ? f = 1 : f = 0;
            for(int j = i; j <= s; j++){
                dp[j] = cs[f][j-1];
                if(q.size() == k){
                    sum -= q.front();
                    if(sum < 0)
                        sum += MOD;
                    q.pop();
                }
                sum = (sum + dp[j]) % MOD;
                q.push(dp[j]);
                cs[!f][j] = sum;
                //cout<<dp[i][j]<<" ";
            }
           // cout<<endl;
        }

        printf("Case %d: %d\n", caseno++, dp[s]);
    }

    return 0;
}
