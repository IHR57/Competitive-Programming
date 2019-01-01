#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

ll n, m, arr[20], ans;

ll lcm(ll a, ll b)
{
    return (a * b) / __gcd(a, b);
}

ll solve(int i, ll j, int num)
{
    if(i == m)
        return 0;
    for(int x = i; x < m; x++){
        ll temp = lcm(arr[x], j);
        if((num + 1) % 2 == 1){
            ans += (n/temp);
        }
        else
            ans -= (n/temp);
        solve(x + 1, temp, num + 1);
    }
}

int main()
{
    int test, caseno = 1;

    scanf("%d", &test);

    while(test--){
        scanf("%lld %lld", &n, &m);
        for(int i = 0; i < m; i++){
            scanf("%lld", &arr[i]);
        }
        ans = 0;
        solve(0, 1, 0);
        printf("Case %d: %lld\n", caseno++, n - ans);
    }

    return 0;
}
