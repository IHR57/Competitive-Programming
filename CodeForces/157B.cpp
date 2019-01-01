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
#define debug (printf("I AM HERE:)\n"))
#define read freopen("input.txt", "r", stdin);
#define write freopen("output.txt", "w", stdout);
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MAX 100005
using namespace std;

typedef vector<double> vd;

int main()
{
    double ans = 0.0, radii;
    vd v;
    int n;

    scanf("%d", &n);

    for(int i = 1; i <= n; i++){
        scanf("%lf", &radii);
        v.pb(radii);
    }

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    for(int i = 0; i < v.size(); i++){
        if(i % 2 == 0){
            ans += (PI * v[i] * v[i]);
        }
        else{
            ans -= (PI * v[i] * v[i]);
        }
    }

    printf("%0.8lf\n", ans + EPS);

    return 0;
}

