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
#define INF 2147483647
#define MOD 1000000007
#define MAX 200005
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> pii;
typedef vector<ii> vii;
typedef priority_queue<int,vector<int>,greater<int> > PQ;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int setBit(int mask, int pos){return mask = mask | (1<<pos);}
bool checkBit(int mask, int pos){return (bool)(mask & (1<<pos));}

int main()
{
    
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int test, n;

    cin>>test;

    while(test--) {
        cin>>n;
        int maxV = 0, total = 0, cnt = 0;
        vector<int> idx(2 * n + 1);

        for(int i = 0; i < 2 * n; i++) {
            int val;
            cin>>val;
            if(val > maxV) {
                if(maxV) {
                    idx[++cnt] = total;
                }
                maxV = val;
                total = 1;
            }
            else {
                total++;
            }
        }

        idx[++cnt] = total;
        vector<bool> dp(n + 1, false);
        dp[0] = 1;
        for(int i = 1; i <= cnt; i++) {
            for(int j = n; j >= idx[i]; j--) {
                dp[j] = dp[j] | dp[j - idx[i]];
            }
        }

        cout<<(dp[n] ? "YES" : "NO")<<endl;
    }
                                                                                                                                                                                                                      
    return 0;
}