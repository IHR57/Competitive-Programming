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
#define fi first
#define se second
#define PI acos(-1)
#define pi 3.1415926535897932384
#define INF 2147483647
#define EPS 1e-8
#define MOD 1000000007
#define MAX 200005
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

vii v;

int solve(vii vp)
{
    int cnt = 0, idx = -1;
    int a = vp[0].fi, b = vp[1].fi;
    int d = (b - a);

    int k = 2;
    for(int i = 2; i < vp.size(); i++){
        int temp = a + k * d;
        //cout<<temp<<endl;
        if(temp != vp[i].fi){
            cnt++;
            idx = vp[i].se;
        }
        else{
            k++;
        }
    }
    if(cnt == 1){
        return idx;
    }
    else if(cnt == 0){
        return vp[0].se;
    }

    a = vp[0].fi, b  = vp[2].fi;
    d = b - a;
    cnt = 0;
    for(int i = 3; i < vp.size(); i++){
        int temp = a + (i - 1) * d;
        if(temp != vp[i].fi){
            cnt++;
        }
    }
    if(cnt == 0){
        return vp[1].se;
    }
    a = vp[1].fi, b = vp[2].fi;
    d = b - a;
    cnt = 0;
    for(int i = 3; i < vp.size(); i++){
        int temp = a + (i - 1) * d;
        if(temp != vp[i].fi){
            cnt++;
        }
    }
    if(cnt == 0){
        return vp[0].se;
    }
    return -1;
}

int main()
{
    fastIO;
    int n, val;

    cin>>n;

    for(int i = 1; i <= n; i++){
        cin>>val;
        v.pb(mp(val, i));
    }

    if(n <= 3){
        cout<<1<<endl;
        return 0;
    }

    sort(v.begin(), v.end());
    int idx = solve(v);
    if(idx != -1){
        cout<<idx<<endl;
        return 0;
    }
    reverse(v.begin(), v.end());
    idx = solve(v);
    cout<<idx<<endl;

    return 0;
}

