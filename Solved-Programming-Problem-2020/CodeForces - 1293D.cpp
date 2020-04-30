//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define mem(a, b) (memset(a, b, sizeof(a)))
#define pb push_back
#define mk make_pair
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

int arr[505][505];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif
    ll x0, y0, xs, ys, t, ax, ay, bx, by;

    cin>>x0>>y0>>ax>>ay>>bx>>by;
    cin>>xs>>ys>>t;

    vector<ll> x, y;
    x.pb(x0), y.pb(y0);

    while(true){
        x.pb(x.back() * ax + bx);
        y.pb(y.back() * ay + by);
        if(x.back() >= 1e16 || y.back() >= 1e16)
            break;
    }

    int n = x.size();

    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            ll len = abs(x[j] - x[i]) + abs(y[j] - y[i]);
            ll temp1 = abs(xs - x[i]) + abs(ys - y[i]);
            ll temp2 = abs(xs - x[j]) + abs(ys - y[j]);
            if(temp1 + len <= t || temp2 + len <= t){
                ans = max(ans, j - i + 1);
            }
        }
    }

    cout<<ans<<endl;

    return 0;
}