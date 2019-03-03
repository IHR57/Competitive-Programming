#include <bits/stdc++.h>
#define MAX 100005
#define MOD 1000000000
using namespace std;

typedef long long ll;

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
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int test, caseno = 1;
    ll m, n, k, b, x, y;
    vector<ll> v;

    scanf("%d", &test);

    while(test--){
        scanf("%lld %lld %lld %lld", &m, &n, &k, &b);
        int blockinFirstRow = 0;
        for(int i = 0; i < b; i++){
            scanf("%lld %lld", &x, &y);
            ll temp = (n * (x - 1)) + y;
            v.push_back(temp);
            if(x == 1)
                blockinFirstRow++;
        }

        sort(v.begin(), v.end());

        ll rem, cnt = 0;

        for(int i = 0; i < v.size(); i++){
            ll temp = v[i];
            if(binary_search(v.begin(), v.end(), temp - n))
                continue;
            while(temp <= (m * n)){
                if(binary_search(v.begin(), v.end(), temp + n)){
                    temp = temp + n;
                }
                else if(temp + n <= m * n){
                    cnt++;
                    break;
                }
                else{
                    break;
                }
            }
        }

        //cout<<cnt<<endl;
        ll result = bigMod(k, n + cnt - blockinFirstRow) * bigMod(k-1, (m*n) - (n + b + cnt - blockinFirstRow)) % MOD;

        printf("Case %d: %lld\n", caseno++, result);

        v.clear();
    }

    return 0;
}
