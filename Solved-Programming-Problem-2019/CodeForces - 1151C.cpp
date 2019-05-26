//Problem ID: CodeForces - 1151C (Problem for Nazar)
//Programmer: IQBAL HOSSAIN     Description: MATH/Constructive Algorithm
//Date: 22/05/19
#include <bits/stdc++.h>
#define MAX 100005
#define MOD 1000000007
using namespace std;

typedef long long ll;

ll bigMod(ll a, ll b)
{
    if(b == 0)
        return 1;
    ll x = bigMod(a, b/2);
    x = (x * x) % MOD;
    if(b % 2 == 1)
        x = (x * a) % MOD;
    return x;
}

struct data{
    ll l, r, s;
};

data block[80];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt",  "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll L, R;
    cin>>L>>R;
    int lb = (int) log2(L) + 1;
    int rb = (int) log2(R) + 1;

    block[1].l = 1, block[1].r = 1, block[1].s = 1;
    for(int i = 2; i <= rb; i++){
        if(i % 2 == 0){
            block[i].l = (block[i-1].l * 2) % MOD;
            block[i].r = (block[i].l + (((1LL<<(i-1)) - 1) * 2) % MOD) % MOD;
        }
        else{
            block[i].l = (block[i-1].l * 2 - 1) % MOD;
            block[i].r = (block[i].l + (((1LL<<(i-1)) - 1) * 2) % MOD) % MOD;
        }
        ll n = (1LL<<(i - 1)) % MOD;
        block[i].s = ((n * ((2 * block[i].l) % MOD + ((n - 1) * 2) % MOD) % MOD) % MOD * bigMod(2, MOD - 2)) % MOD;
        if(block[i].s < 0)
            block[i].s += MOD;
        // cout<<block[i].s<<endl;
    }
    ll res = 0, st, en;
    if(lb == rb){
        st = (L - (1LL<<(lb -1)) + 1) % MOD;
        ll temp  = (block[lb].l + ((st - 1) * 2) % MOD) % MOD;
        en = (R - (1LL<<(lb - 1)) + 1) % MOD;
        res = (((en - st + 1) * ((2 * temp) % MOD + ((en - st) * 2) % MOD) % MOD) % MOD * bigMod(2, MOD - 2)) % MOD;
        //res *= (bigMod(2, MOD - 2)) % MOD;
        if(res < 0)
            res += MOD;
        cout<<res<<endl;
    }
    else{
        st = (L - (1LL<<(lb-1)) + 1) % MOD;
        ll temp = (block[lb].l + ((st - 1) * 2) % MOD) % MOD;
        en = (((1LL<<lb) - 1) - ((1LL<<(lb - 1)) - 1)) % MOD;
        res = (((en - st + 1) * ((2 * temp) % MOD + ((en - st) * 2) % MOD) % MOD) % MOD * bigMod(2, MOD - 2)) % MOD;
        if(res < 0)
            res += MOD;
        //cout<<res<<endl;
        st = 1;
        temp = block[rb].l % MOD;
        en = (R - (1LL<<(rb-1)) + 1) % MOD;
        res += (((en - st + 1) * ((2 * temp) % MOD + ((en - st) * 2) % MOD) % MOD) % MOD * bigMod(2, MOD - 2)) % MOD;
        if(res < 0)
            res += MOD;
        for(int i = lb + 1; i <= rb - 1; i++){
            res += (block[i].s) % MOD;
        }

        cout<<res % MOD<<endl;
    }

    return 0;
}