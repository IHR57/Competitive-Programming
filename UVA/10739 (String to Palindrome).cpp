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
#define debug (printf("PINK FLOYD:)\n"))
#define read freopen("input.txt", "r", stdin);
#define write freopen("output.txt", "w", stdout);
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MAX 1005
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<string> vs;

char str[MAX];
int dp[MAX][MAX];

int solve(int i, int j)
{
    if(i > j)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    if(str[i] == str[j]){
        dp[i][j] = solve(i + 1, j - 1);
    }
    else{
        int ans1 = min(solve(i, j - 1), solve(i + 1, j)) + 1;
        int ans2 = min(ans1, 1 + solve(i + 1, j - 1));
        dp[i][j] = ans2;
    }

    return dp[i][j];
}
int main()
{
	//read; write;
    int test, caseno = 1;

    scanf("%d", &test);

    while(test--){
        scanf("%s", str);
        memset(dp, -1, sizeof(dp));

        int len = strlen(str);

        int result = solve(0, len-1);

        printf("Case %d: %d\n", caseno++, result);
    }

	return 0;
}
