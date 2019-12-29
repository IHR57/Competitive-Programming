//BISMILLAHIR RAHMANIR RAHIM
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <ctime>
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
#define mem(a, b) (memset(a, b, sizeof(a)))
#define read (freopen("input.txt", "r", stdin))
#define write (freopen("output.txt", "w", stdout))
#define fastIO (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0));
#define dis(x1, y1, x2, y2) ((x1-x2) * (x1-x2)) + ((y1-y2) * (y1-y2))
#define debug (printf("PINK FLOYD:)\n"))
#define iosflags (cout<<setiosflags(ios::fixed)<<setprecision(8))
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define pi 3.1415926535897932384
#define INF 2147483647
#define EPS 1e-8
#define MOD 1000000007
#define MAX 5005
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef pair<int, ii> pii;
typedef vector<ii> vii;
typedef priority_queue<int,vector<int>,greater<int> > PQ;

const int inf = 1<<28;
int dirx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int diry[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int fx[] = { -2, -2, -1, -1,  1,  1,  2,  2 };
int fy[] = { -1,  1, -2,  2, -2,  2, -1,  1 };

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

//int dp[MAX][3], arr[MAX], k;
//
//int solve(int pos, int typ)
//{
//    if(pos >= k)
//        return 0;
//    if(dp[pos][typ] != -1)
//        return dp[pos][typ];
//    int ret1 = 0;
//    if(typ == 0){
//        ret1 = arr[pos] + solve(pos + 1, 1);
//        ret1 = max(ret1, arr[pos] + solve(pos + 2, 0));
//    }
//    if(typ == 1){
//        ret1 = arr[pos] + solve(pos + 1, 2);
//        ret1 = max(ret1, arr[pos] + solve(pos + 2, 1));
//    }
//    if(typ == 2){
//        ret1 = arr[pos] + solve(pos + 2, 2);
//    }
//
//    return dp[pos][typ] = ret1;
//}
int csa[MAX], csb[MAX];

int main()
{
	fastIO;
//    string s, str = "";
//
//    cin>>s;
//
//    char prev = '#';
//    int len = s.size();
//
//    int cnt = 0;
//    for(int i = 0; i < len; i++){
//        if(s[i] == prev){
//            cnt++;
//        }
//        else{
//            str += s[i];
//            arr[k++] = cnt;
//            prev = s[i];
//            cnt = 1;
//        }
//    }
//    arr[k++] = cnt;
//    for(int i = 0; i < k - 1; i++){
//        arr[i] = arr[i+1];
//    }
//    k--;
//
//    memset(dp, -1, sizeof(dp));
//    int result;
//    if(str[0] == 'a'){
//        result = solve(0, 0);
//        result = max(result, solve(1, 1));
//    }
//    else{
//        result = solve(0, 1);
//        result = max(result, solve(1, 0));
//    }
//
//    cout<<result<<endl;
    string str;

    cin>>str;

    int n = str.size();

    for(int i = 1; i <= n; i++){
        if(str[i-1] == 'a'){
            csa[i] = csa[i-1] + 1;
            csb[i] = csb[i-1];
        }
        else{
            csb[i] = csb[i-1] + 1;
            csa[i] = csa[i-1];
        }
    }

    int Max = 0;
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            int ans = (csb[j] - csb[i] + 1) + (csa[n] - csa[j]) + csa[i-1];
            Max = max(Max, ans);
        }
    }

    cout<<Max<<endl;

    return 0;
}
