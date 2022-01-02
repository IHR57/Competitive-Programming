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

int caseno = 1;
int ans[MAX];

void addToAns(int num, int dir, int& idxL, int& idxR) {
    if(dir == 1) {
        ans[idxR] = num;
        idxR--;
    }
    else {
        ans[idxL] = num;
        idxL++;
    }
}

void solve()
{
    int n, c;

    cin>>n>>c;

    int minSum = n - 1, maxSum = ((n * (n + 1)) / 2) - 1;

    cout<<"Case #"<<caseno++<<": ";

    if(c < minSum || c > maxSum) {
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }

    int idxL = 0, idxR = n - 1, currD = 0;
    int currN = n, spotLeft = n - 2;

    int target = c;
    REP(i, n) {
        spotLeft = max(0, spotLeft);
        if(currN + spotLeft <= target) {
            currD = !currD;
            addToAns(i + 1, currD, idxL, idxR);
            target -= currN;
        }
        else {
            addToAns(i + 1, currD, idxL, idxR);
            target -= 1;
        }
        currN--, spotLeft--;
    }

    REP(i, n - 1) {
        cout<<ans[i]<<" ";
    }
    cout<<ans[n-1]<<endl;

    return;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int test = 1;

    cin>>test;

    while(test--) {
        solve();
    }

    return 0;
}