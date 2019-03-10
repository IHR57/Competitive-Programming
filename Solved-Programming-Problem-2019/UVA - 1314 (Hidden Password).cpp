//BISMILLAHIR RAHMANIR RAHIM
//Problem ID: UVA - 1314 (Hidden Password)
//Programmer: IQBAL HOSSAIN     Description: Suffix Array
//Date: 07/03/19
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

int n;

vector<int> solve(string s)
{
    int n = (int) s.length();
    const int alphabet = 256;   //total ASCII character

    vector<int> p(n), c(n), cnt(max(alphabet, n), 0);

    for(int i = 0; i < n; i++){
        cnt[s[i]]++;
    }
    for(int i = 1; i < alphabet; i++){
        cnt[i] += cnt[i-1];
    }

    for(int i = 0; i < n; i++)      //counting sort
        p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;

    for(int i = 1; i < n; i++){     //assigning class
        if(s[p[i]] != s[p[i-1]]){
            classes++;
        }
        c[p[i]] = classes - 1;
    }

    vector<int> pn(n), cn(n);

    for(int h = 0; (1<<h) < n; h++){
        for(int i = 0; i < n; i++){
           pn[i] = p[i] - (1<<h);
           if(pn[i] < 0)
               pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        //memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < n; i++)
            cnt[c[pn[i]]]++;

        for(int i = 1; i < classes; i++)
            cnt[i] += cnt[i-1];

        for(int i = n - 1; i >= 0; i--){
            p[--cnt[c[pn[i]]]] = pn[i];
        }

        cn[p[0]] = 0;
        classes = 1;

        for(int i = 1; i < n; i++){
            pii cur = make_pair(c[p[i]], c[(p[i] + ( 1<< h)) % n]);
            pii prev = make_pair(c[p[i-1]], c[(p[i-1] + (1 << h)) % n]);

            if(prev != cur){
                classes++;
            }
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }

    return p;
}


int main()
{
    int test;
    string str;

    cin>>test;

    while(test--){
        cin>>n>>str;
        str += str;
        str += "~";
        vi result = solve(str);
        int m = str.size();

        for(int i = 0; i <= m; i++){
            if(result[i] < n){
                cout<<result[i]<<endl;
                break;
            }
        }
    }

    return 0;
}
