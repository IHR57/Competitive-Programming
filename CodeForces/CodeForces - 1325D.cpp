//Date: 16/03/2020
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
#define MAX 105
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ll u, v;

    cin>>u>>v;

    if((u&1) != (v&1)){
        cout<<-1<<endl;
        return 0;
    }

    if(u > v){
        cout<<-1<<endl;
        return 0;
    }

    if(u == 0 && v == 0){
        cout<<0<<endl;
        return 0;
    }

    if(u == v){
        cout<<1<<endl;
        cout<<u<<endl;
        return 0;
    }

    ll x = (v - u) >> 1;

    if(u & x){
        cout<<3<<endl;
        cout<<u<<" "<<x<<" "<<x<<endl;
    }
    else{
        cout<<2<<endl;
        cout<<(u^x)<<" "<<x<<endl;
    }
    
    return 0;
}
