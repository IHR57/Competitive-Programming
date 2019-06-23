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
#define MAX 100005
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

string s, t;

int main()
{
    fastIO;
    int n;
    string temp;

    cin>>n;

    while(n--){
        s.clear();
        t.clear();
        cin>>temp;
        s += temp;
        cin>>temp;
        t += temp;

        int i = 0, j = 0;
        int len1 = s.size(), len2 = t.size(), cnt1 = 0, cnt2 = 0;
        s += "#", t += "#";

        if(len2 < len1){
            cout<<"NO"<<endl;
            continue;
        }
        char ch1, ch2;
        bool flag = true;
        while(true){
            cnt1 = cnt2 = 0;
            if((i >= len1 && j < len2) || (i < len1 && j >= len2)){
                cout<<"NO"<<endl;
                flag = false;
                break;
            }
            if(i >= len1 && j >= len2){
                break;
            }
            ch1 = s[i];
            if(s[i] == s[i+1]){
                while(s[i] == s[i+1]){
                    cnt1++;
                    ch1 = s[i];
                    i++;
                    if(i >= len1)
                        break;
                }
                i++;
            }
            else{
                i++;
            }
            ch2 = t[j];
            //cout<<ch1<<" "<<ch2<<endl;
            if(ch1 != ch2){
                cout<<"NO"<<endl;
                flag = false;
                break;
            }
            if(t[j] == t[j+1]){
                while(t[j] == t[j+1]){
                    cnt2++;
                    ch2 = t[j];
                    j++;
                    if(j >= len2)
                        break;
                }
                j++;
            }
            else{
                j++;
            }
            if(cnt2 < cnt1){
                cout<<"NO"<<endl;
                flag = false;
                break;
            }
        }

        if(flag)
            cout<<"YES"<<endl;
    }

    return 0;
}

