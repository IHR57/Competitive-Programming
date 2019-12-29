//Problem ID: LightOJ - 1013 (Love Calculator)
//Programmer: IQBAL HOSSAIN     Description: Dynamic Programming
//Date: 12/01/19
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
#define MOD 1000000007
#define MAX 40
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

ll LCS[MAX][MAX], dp[MAX][MAX];
int n, m;
char str1[MAX], str2[MAX];

int main()
{
    int test, caseNo = 1;

    scanf("%d", &test);

    while(test--){
        scanf("%s", str1);
        scanf("%s", str2);

        n = strlen(str1);
        m = strlen(str2);

        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= m; j++){
                if(i == 0 || j == 0)
                    LCS[i][j] = 0;
                else if(str1[i-1] == str2[j-1]){
                    LCS[i][j] = 1 + LCS[i-1][j-1];
                }
                else{
                    LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
                }
            }
        }

        ll minLength = n + m - LCS[n][m];

        for(int i = 0; i <= n; i++){
            dp[i][0] = 1;
        }
        for(int i = 0; i <= m; i++){
            dp[0][i] = 1;
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(str1[i-1] != str2[j-1]){
                    if(LCS[i-1][j] == LCS[i][j-1]){
                        dp[i][j] = dp[i-1][j] + dp[i][j-1];
                    }
                    else if(LCS[i-1][j] > LCS[i][j-1]){
                        dp[i][j] = dp[i-1][j];
                    }
                    else{
                        dp[i][j] = dp[i][j-1];
                    }
                }
                else{
                    dp[i][j] = dp[i-1][j-1];
                }
            }
        }

        printf("Case %d: %lld %lld\n", caseNo++, minLength, dp[n][m]);
    }
    return 0;
}
