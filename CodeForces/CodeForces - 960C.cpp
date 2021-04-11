//Date: 08/02/2020
#include <bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define pi 3.1415926535897932384
#define INF 2147483647
#define EPS 1e-8
#define MAX 200005
using namespace std;
 
typedef long long ll;
typedef pair<int, int> ii;
 
int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

vector<ll> v;

int cntBit(ll n)
{
    int cnt = 0;
    while(n != 0){
        n >>= 1LL;
        cnt++;
    }

    return cnt;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ll x, d;

    ll last = 1e17;

    cin>>x>>d;

    while(x){
        ll tx = cntBit(x);
        if((1LL<<tx) - 1 != x)
            tx--;
        x -= ((1LL<<tx) - 1);
        for(int i = 0; i < tx; i++)
            v.pb(last);
        last -= d;
    }

    cout<<v.size()<<endl;
    for(int i = 0; i < v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    return 0;
}