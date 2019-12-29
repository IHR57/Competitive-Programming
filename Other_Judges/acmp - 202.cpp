//Date: 29/10/19
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
#define MAX 100005
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int m = 53, len;
ll h1[MAX], h2[MAX], p1[MAX], p2[MAX];

ll getHash1(int a, int c)
{
    return (p1[c] *  (h1[a + len] - h1[a] + MOD) % MOD) % MOD;
}

ll getHash2(int a, int c)
{
    return p2[c] * (h2[a+len] - h2[a]);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif
    string str, sub;

    cin>>str;
    cin>>sub;

    len = sub.size();

    str += sub;

    int n = str.size();

    p1[0] = 1, p2[0] = 1;
    for(int i = 1; i <= n; i++){
    	p1[i] = (p1[i-1] * m) % MOD;
        p2[i] = (p2[i-1] * m);
    }

    h1[0] = 0;
    for(int i = 0; i < n; i++){
    	h1[i+1] = (h1[i] + (str[i] - 'a' + 1) * p1[i]) % MOD;
        h2[i+1] = (h2[i] + (str[i] - 'a' + 1) * p2[i]);
    }

    vector<int> res;
    for(int i = 0; i <= n - 2 * len; i++){
        if(getHash1(i, n - len) == getHash1(n - len, i)){
            if(getHash2(i, n - len) == getHash2(n - len, i)){
                res.pb(i);
            }
        }
    }

    for(int i = 0; i < res.size(); i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;

    return 0;
}
