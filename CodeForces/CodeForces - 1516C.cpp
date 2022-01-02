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
    int n;

    cin>>n;

    vi arr(n);

    int sum = 0, foundOdd = 0, oddIdx = -1;
    REP(i, n) {
        cin>>arr[i];
        sum += arr[i];
        if(arr[i] & 1)
            foundOdd = 1, oddIdx = i + 1;
    }

    if((sum % 2 == 1)) {
        cout<<0<<endl;
        return;
    }

    vi dp(sum + 1, 1e9), parent(sum + 1, -1), pos(sum + 1, -1);
    dp[0] = 0;

    REP(j, n) {
        ROF(i, sum, 1) {
            if(arr[j] <= i) {
                if((dp[i-arr[j]] + 1) < dp[i]) {
                    dp[i] = dp[i-arr[j]] + 1;
                    parent[i] = i - arr[j];
                    pos[i] = j;
                }
            }
        }
    }

    int minSum = INF, num;
    for(int i = 0; i < sum; i += 2) {
        if(dp[i] != 1e9) {
            if(dp[(sum - i)/2] == 1e9) {
                if(dp[i] < minSum) {
                    minSum = dp[i];
                    num = i;
                }
            }
        }
    }


    if(minSum == INF) {
        if(foundOdd) {
            cout<<1<<endl;
            cout<<oddIdx<<endl;
            return;
        }
        cout<<n - 1<<endl;
        REP(i, n - 1) {
            cout<<i + 1<<" ";
        }
        cout<<endl;
    }
    else {
        if(minSum > 1) {
            if(foundOdd == 1) {
                cout<<1<<endl;
                cout<<oddIdx<<endl;
                return;
            }
        }
        cout<<minSum<<endl;
        while(parent[num] != -1) {
            cout<<pos[num] + 1<<" ";
            num = parent[num];
        }
        cout<<endl;
    }



    return;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int test = 1;

    //cin>>test;

    while(test--) {
        solve();
    }

    return 0;
}

