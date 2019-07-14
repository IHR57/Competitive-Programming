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
#define MAX 1005
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

vii vp1, vp2;
int start[MAX], arr[MAX], valid[MAX];

int main()
{
	fastIO;

	int n, m, t, l, r;

    cin>>n>>m;

	int k = 1e5;
	arr[0] = 1e5;
	k++;
	for(int i = 1; i <= n; i++){
        arr[i] = k++;
	}

	for(int i = 0; i < m; i++){
        cin>>t>>l>>r;
        if(t == 1){
            start[l] = 1;
            vp1.pb(mp(l, r));
        }
        else
            vp2.pb(mp(l, r));
	}

	for(int i = 0; i < vp2.size(); i++){
        for(int j = 0; j < vp1.size(); j++){
            if(vp2[i].ff >= vp1[j].ff && vp2[i].ss <= vp1[j].ss){
                cout<<"NO"<<endl;
                return 0;
            }
        }
	}

    for(int i = 1; i <= n; i++){
        bool flag = true;
        for(int j = 0; j < vp1.size(); j++){
            if(i >= vp1[j].ff && i <= vp1[j].ss){
                flag = false;
                break;
            }
        }
        if(flag)
            valid[i] = 1;
    }
    for(int i = 1; i <= n; i++){
        if(start[i] && !valid[i]){
            bool flag = true;
            for(int j = 0; j < vp1.size(); j++){
                if(i - 1 >= vp1[j].ff && i <= vp1[j].ss){
                    flag = false;
                    break;
                }
            }
            if(flag)
                valid[i] = 1;
        }
    }

    sort(vp2.begin(), vp2.end());

	for(int i = 0; i < vp2.size(); i++){
        bool flag = false;
        for(int j = vp2[i].ff + 1; j <= vp2[i].ss; j++){
            if(valid[j]){
                if(arr[j] >= arr[j-1]);
                    arr[j] = arr[j-1] - 1;
                flag = true;
                break;
            }
        }
        if(!flag){
            cout<<"NO"<<endl;
            return 0;
        }
	}

    cout<<"YES"<<endl;
	for(int i = 1; i <= n; i++){
        cout<<arr[i]<<" ";
	}
	cout<<endl;

    return 0;
}
