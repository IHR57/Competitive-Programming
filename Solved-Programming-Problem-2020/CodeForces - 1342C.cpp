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

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif
    
    int test;
    ll a, b, q;
    ll l, r;

    cin>>test;

    while(test--){
        cin>>a>>b>>q;
        for(int i = 0; i < q; i++){
            cin>>l>>r;
            ll t = max(a, b);
            int g = __gcd(a, b);
            int lcm = (a * b) / g;
            ll csr = min(r - (r / lcm) * lcm  + 1, t) + (r / lcm) * t;
            l--;
            ll csl = min(l - (l / lcm) * lcm + 1, t) + (l / lcm) * t;

            cout<<(r - l) - (csr - csl)<<" ";
        }
        cout<<endl;
    }

    return 0;
}