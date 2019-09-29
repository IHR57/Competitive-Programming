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

vector<ii> v;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, val;

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>val;
        v.pb(mp(val, i));
    }

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    ll ans = 0;
    for(int i = 0; i < v.size(); i++){
        ans += (ll) (i * v[i].ff + 1);
    }

    cout<<ans<<endl;
    for(int i = 0; i < v.size(); i++){
        cout<<v[i].ss + 1<<" ";
    }
    cout<<endl;

    return 0;
}
