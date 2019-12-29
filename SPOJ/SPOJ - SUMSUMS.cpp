//Problem ID: SPOJ - SUMSUMS (Summing Sums)
//Programmer: IQBAL HOSSAIN     Description: Binary Exponentiation
//Date: 30/01/19
//Problem Link: https://www.spoj.com/problems/SUMSUMS/
#include <bits/stdc++.h>
#define MAX 100005
#define MOD 98765431
using namespace std;

typedef long long ll;

ll c[MAX];

ll bigMod(ll a, ll b)
{
    if(b == 0)
        return 1;
    ll x = bigMod(a, b / 2);
    x = (x * x) % MOD;
    if(b % 2 == 1)
        x = (x * a) % MOD;
    return x;
}

int main()
{
    ll n, t;
    ll sum = 0, value;

    scanf("%lld %lld", &n,  &t);
    //cin>>n>>t;

    for(int i = 0; i < n; i++){
        scanf("%lld", &c[i]);
        //cin>>c[i];
        sum = (sum + c[i]) % MOD;
    }

    if(n == 1){
        //cout<<0<<endl;
        printf("0\n");
        return 0;
    }

    ll res = (bigMod((ll) n - 1, t) * sum ) % MOD;
    ll temp = 0;
    for(int i = 1; i < n; i++){
        if(t % 2 == 0){
            temp = ((temp + (c[i] - c[0]) + MOD) % MOD) % MOD;
        }
        else{
            temp = ((temp + (c[0] - c[i]) + MOD) % MOD) % MOD;
        }
    }

    res = ((res - temp) + MOD) % MOD;

    //cout<<res<<endl;
    res = (res * bigMod(n, MOD - 2) % MOD) % MOD;

    printf("%lld\n", res);
    //cout<<res<<endl;
    for(int i = 1; i < n; i++){
        if(t % 2 == 0){
            printf("%lld\n", (res + ((c[i] - c[0]) + MOD) % MOD) % MOD);
            //cout<<((res + ((c[i] - c[0]) + MOD) % MOD) % MOD)<<endl;
        }
        else{
            printf("%lld\n", (res + ((c[0] - c[i]) + MOD) % MOD) % MOD);
            //cout<<((res + ((c[0] - c[i]) + MOD) % MOD) % MOD)<<endl;
        }
    }

    return 0;
}
