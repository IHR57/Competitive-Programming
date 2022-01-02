//بسم الله الرحمن الرحيم
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define mem(a, b) (memset(a, b, sizeof(a)))
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define min3(a,b,c)     min(a,min(b,c))
#define max3(a,b,c)     max(a,max(b,c))
#define min4(a,b,c,d)   min(a,min(b,min(c,d)))
#define max4(a,b,c,d)   max(a,max(b,max(c,d)))
#define FOR(i,a,b)      for(int i=a;i<=b;i++)
#define ROF(i,a,b)      for(int i=a;i>=b;i--)
#define REP(i,b)        for(int i=0;i<b;i++)
#define all(v)          v.begin(),v.end()
#define SORT(v)         sort(v.begin(),v.end())
#define REV(v)          reverse(v.begin(),v.end())
#define INF 2147483647
#define MOD 1000000007
#define MAX 200005
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> pii;
typedef pair<ll, ll> LL;
typedef vector<ii> vii;
typedef priority_queue<ll,vector<ll>,greater<ll> > PQ;
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int setBit(int mask, int pos){return mask = mask | (1<<pos);}
bool checkBit(int mask, int pos){return (bool)(mask & (1<<pos));}

ll p[10];
int arr[10];
int n, k;

void solve()
{
    int n;
    cin>>n;

    vi arr(n + 1), pos(n + 1);

    FOR(i, 1, n) {
        cin>>arr[i];
        pos[arr[i]] = i;
    }

    int start = -1;
    set<int> s;

    int ans = 0;

    FOR(i, 1, n) {
        int tx = -1;
        if(start == i && arr[i] == i) {
            start = i + 1;
            continue;
        }
        if(s.find(i) != s.end()) {
            ans = max(ans, i - start);
            tx = pos[i] + 1;
        }
        else if(start != -1) {
            if(arr[i] >= start && arr[i] <= i) {
                ans = max(ans, i - start);
                tx = max(tx, pos[arr[i]] + 1);
            }
        }
        if(tx != -1) {
            for(int i = start; i < tx; i++) {
                s.erase(arr[i]);
            }
            start = tx;

        }
        if(start == -1) {
            if(arr[i] == i)
                continue;
            else {
                s.insert(arr[i]);
                start = i;
            }
        }
        s.insert(arr[i]);
    }

    cout<<start<<" "<<ans<<endl;

    return;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int test = 1;

    cin>>test;

    while(test--) {
        solve();
    }

    return 0;
}

