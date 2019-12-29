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

int m = 53;
ll h1[MAX], h2[MAX], p1[MAX], p2[MAX];

ll getHash1(int a, int b, int c)
{
    a--, b--, c--;
    int len = b - a + 1;
    return (p1[c] *  (h1[a + len] - h1[a] + MOD) % MOD) % MOD;
}

ll getHash2(int a, int b, int c)
{
    a--, b--, c--;
    int len = b - a + 1;
    return p2[c] * (h2[a+len] - h2[a]);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //#ifndef ONLINE_JUDGE
    	freopen("substrcmp.in", "r", stdin);
    	freopen("substrcmp.out", "w", stdout);
    //#endif
    string str;

    cin>>str;

    int n = str.size();

    p1[0] = 1, p2[0] = 1;
    for(int i = 1; i <= n; i++){
    	p1[i] = (p1[i-1] * m) % MOD;
        p2[i] = (p2[i-1] * m);
    }

    h1[0] = 0;
    for(int i = 0; i < n; i++){
    	h1[i+1] = (h1[i] + (str[i] - 48) * p1[i]) % MOD;
        h2[i+1] = (h2[i] + (str[i] - 48) * p2[i]);
    }

    int q, a, b, c, d;

    cin>>q;

    for(int i = 0; i < q; i++){
    	cin>>a>>b>>c>>d;
        if((b - a) != (d - c)){
            cout<<"No"<<endl;
            continue;
        }
        if(getHash1(a, b, c) == getHash1(c, d, a) && getHash2(a, b, c) == getHash2(c, d, a)){
            cout<<"Yes"<<endl;
        }
        else
            cout<<"No"<<endl;
    }

    return 0;
}
