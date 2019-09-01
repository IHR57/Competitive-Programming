/*
Template for vjudge.net

	Author: Iqbal Hossain Rasel
	CodeForces: The_Silent_Man
	AtCoder   : IHR57
	TopCoder  : IHR57

*/
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define pi 3.1415926535897932384
#define INF 2147483647
#define EPS 1e-8
#define MOD 1000000007
#define MAX 2005
using namespace std;

typedef unsigned long long ll;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

ll lcm(ll a, ll b)
{
    return (a * b) / __gcd(a, b);
}

ll arr[MAX], cs[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int test, n;

    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);
        cs[0] = 0;
        for(int i = 1; i <= n; i++){
            scanf("%ull", &arr[i]);
            cs[i] = cs[i-1] + arr[i];
        }

        int ans = n;
        for(int i = 1; i <= n; i++){
            ll L = arr[i];
            for(int j = i + 1; j <= n; j++){
                L = lcm(L, arr[j]);
                if((cs[j] - cs[i-1]) % L == 0){
                    ans++;
                }
                if(L > cs[n] - cs[i-1]){
                    break;
                }
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}
