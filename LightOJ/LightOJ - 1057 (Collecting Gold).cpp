//BISMILLAHIR RAHMANIR RAHIM
//Problem ID: LightOJ - 1057 (Collecting Gold)
//Programmer: IQBAL HOSSAIN     Description: Dynamic Programming
//Date: 24/01/19
//Problem Link: http://lightoj.com/volume_showproblem.php?problem=1057
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <list>
#define cos(a) cos(a*pi/180)
#define sin(a) sin(a*pi/180)
#define tan(a) tan(a*pi/180)
#define cosi(a) acos(a)/(pi/180)
#define sini(a) asin(a)/(pi/180)
#define tani(a) atan(a)/(pi/180)
#define read (freopen("input.txt", "r", stdin))
#define write (freopen("output.txt", "w", stdout))
#define fastIO (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0));
#define pb push_back
#define mp make_pair
#define PI acos(-1)
#define pi 3.1415926535897932384
#define INF 2147483647
#define EPS 1e-8
#define MOD 1000000007
#define MAX 16
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef priority_queue<int,vector<int>,greater<int> > pq;

const int inf = 1<<28;
int dirx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int diry[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int dx[]= { -1, 1, 0, 0 };
int dy[]= { 0, 0, -1, 1 };

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int dp[(1<<MAX) + 15][MAX+2];
pii v[MAX+5];
int lim;

int solve(int mask, int last)
{
    if(mask == (1<<lim) - 1){
        return max(abs(v[last].first - v[0].first), abs(v[last].second - v[0].second));
    }

    if(dp[mask][last] != -1)
        return dp[mask][last];

    int Min = inf;
    for(int i = 0; i < lim; i++){
        if(!check(mask, i)){
            Min = min(Min, max(abs(v[i].first - v[last].first), abs(v[i].second - v[last].second)) + solve(Set(mask, i), i));
        }

    }
    dp[mask][last] = Min;

    return dp[mask][last];
}

int main()
{
    //read; write;
    char str[30];
    int test, caseno = 1, n, m;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &n, &m);
        int k = 1;
        for(int i = 0; i < n; i++){
            scanf("%s", str);
            for(int j = 0; j < m; j++){
                if(str[j] == 'x'){
                    v[0] = pii(i, j);
                }
                else if(str[j] == 'g'){
                    v[k++] = pii(i, j);
                }
            }
        }

        lim = k;
        memset(dp, -1, sizeof(dp));

        int result = solve(1, 0);

        printf("Case %d: %d\n", caseno++, result);
    }

    return 0;
}
