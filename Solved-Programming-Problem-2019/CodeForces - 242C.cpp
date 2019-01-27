//BISMILLAHIR RAHMANIR RAHIM
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
#define MAX 100005
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

set<pii> seg;
map<pii, int> dis;

int main()
{
    fastIO;
    int x0, y0, x1, y1, r, a, b, n;

    cin>>x0>>y0>>x1>>y1;
    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>r>>a>>b;
        for(int i = a; i <= b; i++){
            seg.insert(mp(r, i));
        }
    }

    queue<pii> q;
    dis[mp(x0, y0)] = 0;
    q.push(mp(x0, y0));

    while(!q.empty()){
        pii u = q.front();
        q.pop();
        int temp = dis[mp(u.first, u.second)];

        for(int i = 0; i < 8; i++){
            int tx = u.first + dirx[i];
            int ty = u.second + diry[i];
            pii v = mp(tx, ty);
            if(dis.count(v) || !seg.count(v)){
                continue;
            }
            q.push(v);
            dis[v] = temp + 1;
        }
    }

    if(!dis.count(mp(x1, y1))){
        cout<<"-1"<<endl;
    }
    else{
        cout<<dis[mp(x1, y1)]<<endl;
    }

    return 0;
}
