//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define mem(a, b) (memset(a, b, sizeof(a)))
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define INF 2147483647
#define MOD 1000000007
#define MAX 100005
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> pii;
typedef vector<ii> vii;
typedef priority_queue<int,vector<int>,greater<int> > PQ;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

ll n, m, k;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin>>n>>m>>k;

    ll g = __gcd(n, m);
    ll x1 = n / g, x2 = m / g;
    ll sx, sy, tx, ty;
    for(int i = 0; i < k; i++){
        cin>>sx>>sy>>tx>>ty;
        sy--, ty--;
        ll gx, gy;
        if(sx == 1)
            gx = sy / x1;
        else
            gx = sy / x2;
        if(tx == 1)
            gy = ty / x1;
        else
            gy = ty / x2;
        (gx == gy) ? cout<<"YES"<<endl : cout<<"NO"<<endl;
    }
    return 0;
}
