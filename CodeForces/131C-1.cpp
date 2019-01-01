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
#define MAX 100005
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


int main()
{
	//read; write;
	fastIO;

    ll n, m, t, pascals[40][40];
    ll boys, girls, result = 0;

    for(int i = 0; i < 35; i++){
        pascals[i][0] = pascals[i][i] = 1;
        for(int j = 0; j < i; j++){
            pascals[i][j] = pascals[i-1][j] + pascals[i-1][j-1];
        }
    }

    cin>>n>>m>>t;

    for(int i = 4; i <= n; i++){
        boys = (ll) i;
        girls = (t - boys);
        if(girls >= 1 && girls <= m)
            result += (ll) (pascals[n][boys] * pascals[m][girls]);
    }

    cout<<result<<endl;

	return 0;
}
