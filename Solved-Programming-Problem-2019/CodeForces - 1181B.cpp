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

int cs[MAX];

string getSum(string s1, string s2)
{
    if(s1.size() < s2.size())
        swap(s1, s2);
    int len1 = s1.size();
    int len2 = s2.size();
    string res = "";

    int rem = 0;
    for(int i = len1 - 1, j = len2 - 1; j >= 0; i--, j--){
        int temp = (s1[i] - 48) + (s2[j] - 48) + rem;
        if(temp >= 10)
            rem = 1;
        else
            rem = 0;
        res += (temp % 10) + 48;
    }
    for(int i = len1 - len2 - 1; i >= 0; i--){
        int temp = (s1[i] - 48) + rem;
        if(temp >= 10)
            rem = 1;
        else
            rem = 0;
        res += (temp % 10) + 48;
    }
    if(rem)
        res += "1";
    reverse(res.begin(), res.end());
    return res;
}

string comp(string s1, string s2)
{
    if(s1.size() < s2.size())
        return s1;
    else if(s2.size() < s1.size())
        return s2;
    int n = s1.size();
    for(int i = 0; i < n; i++){
        if(s1[i] < s2[i])
            return s1;
        else if(s2[i] < s1[i])
            return s2;
    }
    return s1;
}
int main()
{
	fastIO;
	int n;
	string str;

	cin>>n;
    cin>>str;

    if(n % 2 == 0){
        int k = n / 2;
        while(str[k] == '0'){
            k++;
        }
        string str1 = str.substr(0, k);
        string str2 = str.substr(k, n - k);
        string res = getSum(str1, str2);
        k = n / 2;
        while(str[k] == '0'){
            k--;
        }
        if(k == 0){
            cout<<res<<endl;
            return 0;
        }
        str1 = str.substr(0, k);
        str2 = str.substr(k, n - k);
        res = comp(res, getSum(str1, str2));
        cout<<res<<endl;
    }
    else{
        string str1, str2;
        int k = n / 2;
        if(str[k] != '0'){
            str1 = str.substr(0, k);
            str2 = str.substr(k, n - k + 1);
            //cout<<str1<<" "<<str2<<endl;
            string res = getSum(str1, str2);
            if(str[k+1] == '0'){
                cout<<res<<endl;
                return 0;
            }
            str1 = str.substr(0, k + 1);
            str2 = str.substr(k + 1, n - k + 1);
            //cout<<str1<<" "<<str2<<endl;
            res = comp(res, getSum(str1, str2));
            cout<<res<<endl;
            return 0;
        }
        while(str[k] == '0'){
            k++;
        }
        str1 = str.substr(0, k);
        str2 = str.substr(k, n - k);
        string res = getSum(str1, str2);
        k = n / 2;
        while(str[k] == '0')
            k--;
        if(k <= 0){
            cout<<res<<endl;
            return 0;
        }
        str1 = str.substr(0, k);
        str2 = str.substr(k, n - k);
        //cout<<str1<<" "<<str2<<endl;
        res = comp(res, getSum(str1, str2));
        cout<<res<<endl;
    }

    return 0;
}
