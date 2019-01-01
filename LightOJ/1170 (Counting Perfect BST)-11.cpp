#include <bits/stdc++.h>
#define MAX 100005
#define MOD 100000007
using namespace std;

typedef long long ll;

set<ll> s;
vector<ll> perfectPower;
ll catalan[MAX + 3000];

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

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int test, caseNo = 1;
    ll a, b;

    for(ll i = 2; i < MAX; i++){       //pre-computing all perfect power less than 10^10
        ll j = 2;
        ll temp = i * i;
        while(temp <= 10000000000){
            s.insert(temp);
            j++;
            temp = temp * i;
        }
    }

    for(set<ll>:: const_iterator it = s.begin(); it != s.end(); it++){
        perfectPower.push_back(*it);
    }

    catalan[0] = 1, catalan[1] = 1;
    for(int i = 1; i < (MAX + 3000 -1); i++){       //pre-computing all Catalan number
        catalan[i+1] = (((2 * (2*i+ 1)) * catalan[i]) % MOD * (bigMod((i+2), MOD - 2)) % MOD) % MOD;        //recursive formula for Catalan number
    }

    scanf("%d", &test);

    while(test--){
        scanf("%lld %lld", &a, &b);
        int l = lower_bound(perfectPower.begin(), perfectPower.end(), a) - perfectPower.begin();
        int r = lower_bound(perfectPower.begin(), perfectPower.end(), b) - perfectPower.begin();

        if(perfectPower[l] > b && perfectPower[r] > b)
            printf("Case %d: 0\n", caseNo++);
        else if((perfectPower[l] == a && perfectPower[r] == b) || perfectPower[r] == b){
            printf("Case %d: %lld\n", caseNo++, catalan[r-l+1]);
        }
        else{
            printf("Case %d: %lld\n", caseNo++, catalan[r-l]);
        }
    }

    return 0;
}
