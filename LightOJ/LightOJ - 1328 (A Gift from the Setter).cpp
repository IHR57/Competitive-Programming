//Problem ID: LightOJ - 1328 (A Gift From the Setter)
//Programmer: IQBAL HOSSAIN     Description: Greedy
//Date: 26/02/19
#include <bits/stdc++.h>
#define MAX 100005
#define MOD 1000007
using namespace std;

typedef long long ll;

ll arr[MAX];

int main()
{
    int test, caseno = 1, n;
    ll k, c;

    scanf("%d", &test);

    while(test--){
        scanf("%lld %lld %d %lld", &k, &c, &n, &arr[0]);

        ll sum = arr[0];
        for(int i = 1; i < n; i++){
            arr[i] = ((k * arr[i-1]) % MOD + c) % MOD;
//            cout<<arr[i]<<" ";
            sum += arr[i];
        }

        ll ans = 0;
        int rem = n;

        sort(arr, arr + n);

        for(int i = 0; i < n - 1; i++){
            ans += (sum - (rem * arr[i]));
            sum -= arr[i];
            rem--;
        }

        printf("Case %d: %lld\n", caseno++, ans);
    }

    return 0;
}
