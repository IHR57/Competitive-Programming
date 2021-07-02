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
#define EPS 1e-8
#define MOD 998244353
#define MAX 100005
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

int primes[MAX/10], counter = 0, mark[MAX];
map<int, int> mp[2];

void genSieve()
{
    int limit = sqrt(MAX + 2);

    mark[1] = 1;
    for(int i = 2; i < MAX; i += 2)
        mark[i] = 1;

    primes[counter++] = 2;
    for(int i = 3; i < MAX; i += 2) {
        if(!mark[i]) {
            primes[counter++] = i;
            if(i <= limit) {
                for(int j = i * i; j < MAX; j += i * 2)
                    mark[j] = 1;
            }
        }
    }
}

void factorize(int n, int type)
{
    int idx = 0, pf = primes[idx];
    while(pf * pf <= n) {
        if(n % pf == 0) {
            int cnt = 0;
            while(n % pf == 0) {
                n /= pf;
                cnt++;
            }
            mp[type][pf] = cnt;
        }
        pf = primes[++idx];
    }

    if(n != 1) {
        mp[type][n] = 1;
    }
}

void solve()
{
    int a, b, k;

    cin>>a>>b>>k;

    mp[0].clear(); mp[1].clear();

    factorize(a, 0);
    factorize(b, 1);

    int cnt_big = 0, cnt_small = 0, cnt_not_found = 0, cnt_equal = 0, mx = 0, sz = 0;
    for(map<int, int> :: iterator it = mp[0].begin(); it != mp[0].end(); it++) {
        if(!mp[1].count(it->ff)) {
            cnt_not_found++;
        }
        if(it->ss > mp[1][it->ff])
            cnt_big++;
        else if(it->ss < mp[1][it->ff])
            cnt_small++;
        else
            cnt_equal++;
        mx += it->ss;
        sz++;
    }

    int not_found = 0;
    for(map<int, int> :: iterator it = mp[1].begin(); it != mp[1].end(); it++) {
        mx += it->ss;
        if(!mp[0].count(it->ff))
            not_found++;
    }


    int mn = INT_MAX;
    //cout<<cnt_big<<" "<<cnt_equal<<" "<<cnt_small<<" "<<sz<<endl;
    if(cnt_not_found == sz) {
        mn = 2;
        if(a == 1 && b == 1) {
            mn = 0;
        }
        else if(a == 1 || b == 1)
            mn = 1;
    }
    else if((cnt_big + cnt_equal == sz && not_found == 0) || (cnt_small + cnt_equal == sz)) {
        mn = 1;
        if(a == b)
            mn = 2;
    }
    else
        mn = 2;


    bool flag = !(k < mn || k > mx);
    cout<<"NO\0YES" + 3 * flag<<endl;

    return;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int test = 1;

    genSieve();
    cin>>test;

    while(test--) {
        solve();
    }

    return 0;
}

