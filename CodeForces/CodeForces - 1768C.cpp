//BISMILLAHIR RAHMANIR RAHIM
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
#define RSORT(v)        sort(v.rbegin(),v.rend())
#define REV(v)          reverse(v.begin(),v.end())
#define INF 2147483647
#define MOD 998244353
#define MAX 1000005
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> pii;
typedef pair<ll, ll> LL;
typedef vector<ii> vii;
typedef priority_queue<int,vector<int>,greater<int> > PQ;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int setBit(int mask, int pos){return mask = mask | (1<<pos);}
bool checkBit(int mask, int pos){return (bool)(mask & (1<<pos));}

void buildArray(vector<int>& arr, vector<int>& newArr) {
    int n = arr.size();
    vector<bool> isPresent(n + 1, false);
    set<int> s;

    REP(i, n) isPresent[newArr[i]] = true;

    s.insert(0);
    REP(i, n) if(!isPresent[i + 1])    s.insert(i + 1);

    REP(i, n) {
        if(newArr[i] == 0) {
            auto idx = s.upper_bound(arr[i]);
            if((idx == s.end() || *idx > arr[i]))
                idx--;
            newArr[i] = *idx;
            s.erase(*idx);
        }
    }
}

void solve() {
    int n;

    cin>>n;

    vi arr(n), cnt(n + 1, 0);
    bool isPossible = true;

    REP(i, n) {
        cin>>arr[i];
        cnt[arr[i]]++;
        if(cnt[arr[i]] > 2) {
            isPossible = false;
        }
    }

    if(!isPossible) { cout<<"NO"<<endl; return; }

    vi tmp = arr;
    SORT(tmp);

    REP(i, n) {
        if(tmp[i] < (i + 1)) {
            cout<<"NO"<<endl;
            return;
        }
    }

    cout<<"YES"<<endl;
    vi p(n), q(n);

    REP(i, n + 1)   cnt[i] = 0;

    REP(i, n) {
        if(!cnt[arr[i]]) {
            p[i] = arr[i];
        }
        else {
            q[i] = arr[i];
        }
        cnt[arr[i]]++;
    }

    buildArray(arr, p);
    buildArray(arr, q);

    REP(i, n) cout<<p[i]<<" "; cout<<endl;
    REP(i, n) cout<<q[i]<<" "; cout<<endl;

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

