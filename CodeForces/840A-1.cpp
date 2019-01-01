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
#define MAX 200005
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

struct data{
    int value, idx;
};

bool compare(data A, data B)
{
    if(A.value == B.value){
        return A.idx > B.idx;
    }
    return A.value < B.value;
}

vector<data> vData;

int main()
{
    //read; write;
    fastIO;

    int x, m, temp[MAX];
    vi v;

    cin>>m;

    for(int i = 0; i < m; i++){
        cin>>x;
        v.pb(x);
    }

    for(int i = 0; i < m; i++){
        cin>>x;
        data t;
        t.value = x, t.idx = i;
        vData.pb(t);
    }

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    sort(vData.begin(), vData.end(), compare);

    for(int i = 0; i < v.size(); i++){
        temp[vData[i].idx] = v[i];
    }

    for(int i = 0; i < m; i++){
        cout<<temp[i]<<" ";
    }

    cout<<endl;

    return 0;
}
