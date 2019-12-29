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
#define f first
#define s second
#define MAX 100005
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vs;
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

typedef pair<int, int> ii;
typedef pair<int, ii> pii;

vector<pii> vp;
string word[MAX];
int mark[MAX];

bool compare(pii A, pii B)
{
    if(A.s.f == B.s.f)
        return A.s.s < B.s.s;
    return A.s.f < B.s.f;
}

bool isVowel(char ch)
{
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        return true;
    return false;
}

int getValue(char ch)
{
    if(ch == 'a')
        return 0;
    else if(ch == 'e')
        return 1;
    else if(ch == 'i')
        return 2;
    else if(ch == 'o')
        return 3;
    else
        return 4;
}

int main()
{
    fastIO;
    #ifndef ONLINE_JUDGE
        read; write;
    #endif
    int n;

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>word[i];
        int cnt = 0, last;
        char ch;
        int len = word[i].size();
        for(int j = 0; j < len; j++){
            if(isVowel(word[i][j])){
                cnt++;
                last = getValue(word[i][j]);
            }
        }
        vp.pb(mp(i, mp(cnt, last)));
    }

    sort(vp.begin(), vp.end(), compare);
    vector<pii> vp1, vp2;
    // for(int i = 0; i < vp.size(); i++){
    //     cout<<vp[i].f<<" "<<vp[i].s.f<<" "<<vp[i].s.s<<endl;
    // }
    int idx = 1;
    while(idx <= vp.size()){
        if(vp[idx].s.f == vp[idx-1].s.f && vp[idx].s.s == vp[idx-1].s.s){
            vp1.pb(mp(vp[idx-1].f, mp(vp[idx-1].s.f, vp[idx-1].s.s)));
            vp1.pb(mp(vp[idx].f, mp(vp[idx].s.f, vp[idx].s.s)));
            mark[idx-1] = mark[idx] = 1;
            idx += 2;
        }
        else{
            idx++;
        }
    }
    idx = 1;
    vector<pii> vpt;
    for(int i = 0; i < vp.size(); i++){
        if(!mark[i])
            vpt.pb(mp(vp[i].f, mp(vp[i].s.f, vp[i].s.s)));
    }
    while(idx < vpt.size()){
        if(vpt[idx].s.f == vpt[idx-1].s.f){
            vp2.pb(mp(vpt[idx-1].f, mp(vpt[idx-1].s.f, vpt[idx-1].s.s)));
            vp2.pb(mp(vpt[idx].f, mp(vpt[idx].s.f, vpt[idx].s.s)));
            idx += 2;
        }
        else
            idx++;
    }

    // for(int i = 0; i < vp1.size(); i++){
    //     cout<<vp1[i].f<<" "<<vp1[i].s.f<<" "<<vp1[i].s.s<<endl;
    // }

    if(vp1.size() <= 1){
        cout<<0<<endl;
        return 0;
    }
    int temp1 = vp1.size() / 2, temp2 = vp2.size() / 2;
    int ans = 0, ans1 = min(temp1, temp2), res = 0;
    res += ans1;
    if(vp1.size() > (2 * ans1)){
        ans += (vp1.size() - vp2.size()) / 4;
        res += ans;
    }

    cout<<res<<endl;
    for(int i = 0; i < ans1 * 2; i += 2){
        cout<<word[vp2[i].f]<<" "<<word[vp1[i].f]<<endl;
        cout<<word[vp2[i+1].f]<<" "<<word[vp1[i+1].f]<<endl;
    }

    if(ans > 0){
        int k = 0;
        for(int i = 2 * ans1; k < ans; i += 4){
            //cout<<"I AM HERE"<<endl;
            cout<<word[vp1[i+2].f]<<" "<<word[vp1[i].f]<<endl;
            cout<<word[vp1[i+3].f]<<" "<<word[vp1[i+1].f]<<endl;
            k++;
        }
    }


    return 0;
}
