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

int cnt[60];

int main()
{
	fastIO;
	map<string, int> MP;
	string a, b, c;

	MP["1m"] = 1, MP["2m"] = 2, MP["3m"] = 3, MP["4m"] = 4, MP["5m"] = 5, MP["6m"] = 6, MP["7m"] = 7, MP["8m"] = 8, MP["9m"] = 9;
	MP["1p"] = 21, MP["2p"] = 22, MP["3p"] = 23, MP["4p"] = 24, MP["5p"] = 25, MP["6p"] = 26, MP["7p"] = 27, MP["8p"] = 28, MP["9p"] = 29;
	MP["1s"] = 41, MP["2s"] = 42, MP["3s"] = 43, MP["4s"] = 44, MP["5s"] = 45, MP["6s"] = 46, MP["7s"] = 47, MP["8s"] = 48, MP["9s"] = 49;

	cin>>a>>b>>c;
	cnt[MP[a]]++, cnt[MP[b]]++, cnt[MP[c]]++;

	for(int i = 1; i <= 9; i++){
        if(cnt[i] && cnt[i+1] && cnt[i+2]){
            cout<<"0"<<endl;
            return 0;
        }
        else if(cnt[i] == 3){
            cout<<"0"<<endl;
            return 0;
        }
	}
	for(int i = 21; i <= 29; i++){
        if(cnt[i] && cnt[i+1] && cnt[i+2]){
            cout<<"0"<<endl;
            return 0;
        }
        else if(cnt[i] == 3){
            cout<<"0"<<endl;
            return 0;
        }
	}

	for(int i = 41; i <= 49; i++){
        if(cnt[i] && cnt[i+1] && cnt[i+2]){
            cout<<"0"<<endl;
            return 0;
        }
        else if(cnt[i] == 3){
            cout<<"0"<<endl;
            return 0;
        }
	}

	for(int i = 1; i <= 9; i++){
        if((cnt[i] && cnt[i+1]) || (cnt[i] && cnt[i+2])){
            cout<<"1"<<endl;
            return 0;
        }
        else if(cnt[i] == 2){
            cout<<"1"<<endl;
            return 0;
        }
	}

	for(int i = 21; i <= 29; i++){
        if((cnt[i] && cnt[i+1]) || (cnt[i] && cnt[i+2])){
            cout<<"1"<<endl;
            return 0;
        }
        else if(cnt[i] == 2){
            cout<<"1"<<endl;
            return 0;
        }
	}

	for(int i = 41; i <= 49; i++){
        if((cnt[i] && cnt[i+1]) || (cnt[i] && cnt[i+2])){
            cout<<"1"<<endl;
            return 0;
        }
        else if(cnt[i] == 2){
            cout<<"1"<<endl;
            return 0;
        }
	}

	cout<<"2"<<endl;

    return 0;
}
