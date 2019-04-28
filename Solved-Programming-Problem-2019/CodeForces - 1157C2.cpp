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
#define MAX 200005
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
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int fx[] = { -2, -2, -1, -1,  1,  1,  2,  2 };
int fy[] = { -1,  1, -2,  2, -2,  2, -1,  1 };

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int arr[MAX], n;
set<int> s;
string str;

int main()
{
    fastIO;

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    int i = 0, j = n - 1, Max = 0;
    while(i <= j){
        if(arr[i] == arr[j]){
            int cnt1 = 1, cnt2 = 1;
            if(arr[i] <= Max)
                break;
            for(int k = i + 1; k <= j; k++){
                if(arr[k] > arr[k-1])
                    cnt1++;
                else
                    break;
            }
            for(int k = j - 1; k >= i; k--){
                if(arr[k] > arr[k+1])
                    cnt2++;
                else
                    break;
            }
            if(cnt1 >= cnt2){
                for(int k = 0; k < cnt1; k++){
                    str += "L";
                }
            }
            else{
                for(int k = 0; k < cnt2; k++){
                    str += "R";
                }
            }
            break;
        }
        else{
            bool flag = false;
            if((arr[i] < arr[j] || arr[j] <= Max) && arr[i] > Max){
                str += "L";
                Max = arr[i];
                i++;
                flag = true;
            }
            else if((arr[j] < arr[i] || arr[i] <= Max) && arr[j] > Max){
                str += "R";
                Max = arr[j];
                j--;
                flag = true;
            }
            if(!flag){
                break;
            }
        }
    }
    cout<<str.size()<<endl;
    cout<<str<<endl;

    return 0;
}

