#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cstdlib>
#include <list>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <iomanip>
#include <stack>
#define MAX 1000005
#define pb push_back
#define all(v) (v.begin(), v.end())
#define mem(a, b) memset(a, b, sizeof(a))
#define EPS 1e-10
#define PI acos(-1)
#define pi 2*acos(0)
#define MOD 1000000007
#define INF 2147483647
#define mp make_pair
#define sin(a) sin(a*pi/180)
#define cos(a) cos(a*pi/180)
#define tan(a) tan(a*pi/180)
#define sini(a) asin(a) / (pi/180)
#define cosi(a) acos(a) / (pi/180)
#define tani(a) atan(a) / (pi/180)
#define dis(x1, y1, x2, y2) ((x1-x2) * (x1-x2)) + ((y1-y2) * (y1-y2))
#define read freopen("input.txt", "r", stdin);
#define write freopen("output.txt", "w", stdout);
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<string> vs;

ll factorial[MAX];

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

ll nCr(int n, int k)
{
    return (factorial[n] * ((bigMod(factorial[k], MOD - 2) * bigMod(factorial[n-k], MOD - 2)) % MOD)) % MOD;
}

int main()
{
    //read; write;
    int test, x, y;
    ll result;

    factorial[0] = 1;
    for(int i = 1; i < MAX; i++){
        factorial[i] = (i * factorial[i-1]) % MOD;
    }

    scanf("%d", & test);

    while(test--){
        scanf("%d %d", &x, &y);
        ll u = nCr(y, 3);
        ll v = nCr(x - 1, 3);
        result = u - v;
        result = (result + MOD) % MOD;
        printf("%lld\n", result);
    }

    return 0;
}
