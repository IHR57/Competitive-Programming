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
#define PI acos(-1)
#define pi 3.1415926535897932384
#define INF 2147483647
#define EPS 1e-8
#define MOD 1000000007
#define MAX 505
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef vector<pii> vii;
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

int cell[MAX][MAX];

int main()
{
    fastIO;
    #ifndef ONLINE_JUDGE
        read; write;
    #endif
    int r, c;
    char str[600];
    cin>>r>>c;

    for(int i = 0; i < r; i++){
        cin>>str;
        for(int j = 0; j < c; j++){
            if(str[j] == '*')
                cell[i][j] = 1;
        }
    }

    bool found = false;;
    for(int i = 1; i < r - 1; i++){
        for(int j = 1; j < c - 1; j++){
            if(cell[i][j] == 1){
                bool flag = true;
                for(int k = 0; k < 4; k++){
                    int tx = i + dx[k];
                    int ty = j + dy[k];
                    if(cell[tx][ty] == 0){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    cell[i][j] = 0;
                    int k = i - 1;
                    while(cell[k][j] == 1 && k >= 0){
                        cell[k][j] = 0;
                        k--;
                    }
                    k = i + 1;
                    while(cell[k][j] == 1 && k < r){
                        cell[k][j] = 0;
                        k++;
                    }
                    k = j - 1;
                    while(cell[i][k] == 1 && k >= 0){
                        cell[i][k] = 0;
                        k--;
                    }
                    k = j + 1;
                    while(cell[i][k] == 1 && k < c){
                        cell[i][k] = 0;
                        k++;
                    }
                    found = true;
                    break;
                }
            }
        }
        if(found)
            break;
    }

    if(!found){
        cout<<"NO"<<endl;
        return 0;
    }
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(cell[i][j] == 1){
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }

    cout<<"YES"<<endl;

    return 0;
}
