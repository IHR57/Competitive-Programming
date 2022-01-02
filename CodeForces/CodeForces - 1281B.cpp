//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define mem(a, b)       memset(a, b, sizeof(a))
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
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1)
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
    string str1, str2;

    cin>>str1>>str2;

    int n = str1.size();

    int minChar = 50;
    vector<ii> ans(n + 1);
    for(int i = n - 1; i >= 0; i--) {
        if(str1[i] - 'A' < minChar) {
            minChar = (str1[i] - 'A');
            ans[i].ff = minChar;
            ans[i].ss = i;
        }
        else {
            ans[i].ff = ans[i+1].ff;
            ans[i].ss = ans[i+1].ss;
        }
    }

    for(int i = 0; i < n - 1; i++) {
        int x = str1[i] - 'A';
        if(ans[i+1].ff < x) {
            swap(str1[i], str1[ans[i+1].ss]);
            break;
        }
    }

    int m = str2.size();

    for(int i = 0; i < min(n, m); i++) {
        if(str1[i] > str2[i]) {
            cout<<"---"<<endl;
            return;
        }
        else if(str1[i] < str2[i]) {
            cout<<str1<<endl;
            return;
        }
    }

    if(n == m) {
        cout<<"---"<<endl;
    }
    else if(n > m) {
        cout<<"---"<<endl;
    }
    else {
        cout<<str1<<endl;
    }

    return;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int test = 1;

    cin>>test;

    while(test--) {
        solve();
    }

    return 0;
}