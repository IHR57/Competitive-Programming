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
#include <iterator>
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

int n, m, k;
int f[MAX], s[MAX], required[MAX*10], a[2*MAX];
vector<pii> vp;

int main()
{
    //read; write;
    fastIO;

    cin>>n>>m>>k;

    int c = 0;
    for(int i = 1; i <= n; i++){
        cin>>f[i];
    }

    for(int i = 1; i <= m; i++){
        cin>>s[i];
        vp.pb(make_pair(s[i], i));
    }

    sort(f + 1, f + n + 1);
    sort(vp.begin(), vp.end());

    for(int i = 0; i < MAX*10; i++)
        required[i] = k;

    vi v;

    int temp = 1e7 + 10;

    for(int i = n; i >= 1; i--){
        if(f[i] < temp)
            temp = f[i];
        while(temp >= 0 && required[temp] == 0)
            temp--;
        if(temp < 0){
            cout<<-1<<endl;
            return 0;
        }
        required[temp]--;
    }

    temp = 1e7 + 10;
    vi ans;

    for(int i = vp.size() - 1; i >= 0; i--){
        if(vp[i].first < temp)
            temp = vp[i].first;

        while(temp >= 0 && required[temp] == 0)
            temp--;
        if(temp < 0)
            break;
        ans.pb(vp[i].second);
        required[temp]--;
    }

    cout<<ans.size()<<endl;
    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}
