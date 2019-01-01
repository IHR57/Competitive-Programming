#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

ll factorialPower(ll n, ll p)
{
    ll freq = 0;
    ll x = n;

    while(x){
        freq += x / p;
        x = x / p;
    }

    return freq;
}

int main()
{
    int test, caseNo = 1;
    ll n, x, y, result, ans;

    scanf("%d", &test);

    while(test--){
        scanf("%lld", &n);
        ll low = n, high = 5 * n, mid;
        ans = -1;
        while(low <= high){
            mid = (low + high + 1) / 2;
            x = factorialPower(mid, 2);      //frequency of 2
            y = factorialPower(mid, 5);      //frequency of 5
            result = min(x, y);

            if(result == n){
                ans = mid;
                break;
            }
            else if(result > n){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        if(ans != -1){
            printf("Case %d: %lld\n", caseNo++, ans - (ans % 5));
        }
        else{
            printf("Case %d: impossible\n", caseNo++);
        }
    }

    return 0;
}
