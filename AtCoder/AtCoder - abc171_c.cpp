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

    vector<ll> v;
    v.pb(0);
    ll pow = 1;
    vector<ll> pow26(12);
    pow26[0] = 1;
    for(int i = 1; i <= 10; i++) {
        pow26[i] = 26 * pow26[i-1];
        ll temp = v.back() + (pow26[i]);
        v.pb(temp);
    }

    ll n;

    cin>>n;

    int k;
    for(int i = 0; i < 11; i++) {
        if(v[i] >= n)
            break;
        k = i;
    }

    ll rem = n - v[k] - 1;

    string ans = "";
    for(int i = k; i >= 0; i--) {
        int x = rem / pow26[i];
        ans += (char) (x + 97);
        rem -= (x * pow26[i]);
    }

    cout<<ans<<endl;

    return 0;
}
