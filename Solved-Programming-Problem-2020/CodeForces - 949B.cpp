//Date: 19/02/2020
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
typedef unsigned long long ull;
typedef pair<int, int> ii;
 
int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int arr[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ll n, q;

    cin>>n>>q;

    for(int i = 0; i < q; i++){
        ll x;
        cin>>x;

        if(x & 1){
            x = (x + 1) >> 1LL;
            cout<<x<<endl;
        }
        else{
            ll t = (x >> 1LL);
            ll tx = (n - t);
            while(tx % 2 == 0){
                tx >>= 1LL;
            }
            cout<<(n - (tx >> 1LL))<<endl;
        }
    }

    return 0;
}