//Date: 26/12/19
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define pi 3.1415926535897932384
#define INF 2147483647
#define EPS 1e-8
#define MOD 1000000007
#define MAX 15000005
using namespace std;

typedef long long ll;
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
    
    ll n, m, k;
    cin>>n>>m>>k;
    bool flag = false;

    ll temp = (n * m);
    if(k % 2 == 0){
        flag = true;
        k /= 2;
    }
    if(temp % k != 0){
        cout<<"NO"<<endl;
        return 0;
    }

    ll g = __gcd(n, k);
    k /= g;
    ll x  = n / g;

    g = __gcd(m, k);
    k /= g;
    ll y = m / g;

    if(!flag){
        if(x < n){
            x *= 2;
        }
        else{
            y *= 2;
        }
    }

    cout<<"YES"<<endl;
    cout<<0<<" "<<0<<endl;
    cout<<x<<" "<<0<<endl;
    cout<<0<<" "<<y<<endl;

    return 0;
}
