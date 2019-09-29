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
 
typedef unsigned long long ll;
typedef pair<int, int> ii;
 
int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}
 
vector<int> a, b, c;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, m, k, val;

    cin>>n>>m>>k;
    set<int> s, t;
    for(int i = 0; i < n; i++){
        cin>>val;
        t.insert(val);
    }
    for(set<int> :: iterator it = t.begin(); it != t.end(); it++){
        a.pb(*it);
    }
    t.clear();

    for(int i = 0; i < m; i++){
        cin>>val;
        s.insert(val);
    }
    for(int i = 0; i < k; i++){
        cin>>val;
        t.insert(val);
    }
    for(set<int> :: iterator it = t.begin(); it != t.end(); it++){
        c.pb(*it);
    }

    ll ans = 0;
    for(set<int> :: iterator it = s.begin(); it != s.end(); it++){
        int idx1 = upper_bound(a.begin(), a.end(), *it) - a.begin();
        int idx2 = upper_bound(c.begin(), c.end(), *it) - c.begin();
        ans += (1LL * idx1 * idx2);
    }

    cout<<ans<<endl;

    return 0;
}