//Date: 18/10/19
#include <bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define pi 3.1415926535897932384
#define INF 2147483647
#define EPS 1e-8
#define MOD 1000000007
#define MAX 200005
using namespace std;
 
typedef long long ll;
typedef pair<int, int> ii;
 
int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

string res, cur, str;

int KMP(string s)
{
    int n = s.length();
    vector<int> p(n);
    for(int i = 1; i < n; i++){
        int j = p[i-1];
        while(j > 0 && s[i] != s[j])
            j = p[j-1];
        if(s[i] == s[j])
            j++;
        p[i] = j;
    }

    return p[n-1];
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    int n;

    cin>>n;

    cin>>res;

    for(int i = 1; i < n; i++){
        cin>>cur;
        int x = res.length(), y = cur.length();
        int len = min(x, y);
        str = cur + "#" + res.substr(x - len, len);
        int match = KMP(str);
        res += cur.substr(match, y - match);
        //cout<<prev<<endl;
    }

    cout<<res<<endl;

    return 0;
}