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
#define all(v) v.begin(),v.end()
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
typedef priority_queue<int,vector<int>,greater<int> > PQ;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int setBit(int mask, int pos){return mask = mask | (1<<pos);}
bool checkBit(int mask, int pos){return (bool)(mask & (1<<pos));}

void solve()
{
    string str;
    int n;

    cin>>n>>str;

    map<string, int>  mp;

    REP(i, n) {
        string s = "";
        FOR(j, i, n - 1) {
            s += str[j];
            mp[s] = 1;
        }
    }

    int p[5];
    p[0] = 1, p[1] = 26, p[2] = 676, p[3] = 17576, p[4] = 456976;

    for(int i = 0; ; i++) {
        int k = 0;
        int tx = i;
        while(tx / 26 != 0) {
            tx /= 26;
            k++;
        }

        tx = i;
        string st = "";
        ROF(j, k, 0) {
            st += char(((tx == -1) ? ((tx + 1) % 26) : tx % 26) + 97);
            tx = (tx / p[j] - 1);
        }
        reverse(st.begin(), st.end());
        //cout<<st<<endl;
        if(mp[st] == 0) {
            cout<<st<<endl;
            return;
        }

    }

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

