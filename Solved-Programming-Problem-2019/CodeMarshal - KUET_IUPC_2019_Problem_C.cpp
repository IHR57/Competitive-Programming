#include <bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1)
//Problem ID: KUET IUPC 2019 (Problem C)
//Programmer: IQBAL HOSSAIN     Description: Math/Combinatorics/Bit Manipulation
//Date: 12/09/19
//Problem Link: https://algo.codemarshal.org/contests/kuet-iupc-19/problems/C
#define pi 3.1415926535897932384
#define INF 2147483647
#define EPS 1e-8
#define MOD 1000000007
#define MAX 100005
using namespace std;

typedef unsigned long long ll;
typedef pair<int, int> ii;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int arr[MAX];
int cs[MAX][32];
ll p2[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifdef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, q, caseno = 1;

    scanf("%d %d", &n, &q);
    p2[0] = 1;
    for(int i = 1; i < MAX; i++){
        p2[i] = (p2[i-1] * 2) % MOD;
    }

    for(int i = 1; i <= n; i++){
        scanf("%d", &arr[i]);
        for(int j = 0; j <= 30; j++){
            if(check(arr[i], j)){
                cs[i][j] = cs[i-1][j] + 1;
            }
            else
                cs[i][j] = cs[i-1][j];
        }
    }
    int L, R;
    for(int i = 0; i < q; i++){
        scanf("%d %d", &L, &R);
        ll ans = 0;
        for(int j = 0; j <= 30; j++){
            int one = cs[R][j] - cs[L-1][j];
            int zero = (R - L + 1) - one;
            if(one >= 1)
                ans += (((1 << j) * ((p2[one-1] * p2[zero]) % MOD)) % MOD) % MOD;
            ans %= MOD;
        }
        printf("%lld\n", ans);
    }


    return 0;
}
