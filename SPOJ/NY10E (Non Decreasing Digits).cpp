#include <bits/stdc++.h>
#define MAX 100
using namespace std;

typedef long long ll;

ll dp[MAX];

int main()
{
    vector<ll> t1, t2;
    int n, caseNo, test;

    dp[1] = 10, dp[2] = 55;
    int k = 10;

    for(int i = 0; i < 10; i++)
        t1.push_back(k--);

    for(int i = 3; i <= 64; i++){
        dp[i] += dp[i-1];
        ll value = dp[i-1];
        for(int j = 0; j < 9; j++){
            dp[i] += (value - t1[j]);
            value -= t1[j];
            //cout<<value<<endl;
        }
        ll v = dp[i-1];
        t2.push_back(dp[i-1]);
        for(int j = 1; j < 10; j++){
            t2.push_back(v - t1[j-1]);
            v -= t1[j-1];
        }
        t1 = t2;
        t2.clear();
    }

    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &caseNo, &n);
        printf("%d %lld\n", caseNo, dp[n]);
    }

    return 0;
}
