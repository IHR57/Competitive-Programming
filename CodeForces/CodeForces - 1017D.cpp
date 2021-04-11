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
#define MOD 998244353
#define MAX 1005
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> pii;
typedef priority_queue<int,vector<int>,greater<int> > PQ;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int setBit(int mask, int pos) { return mask = mask | (1<<pos); }
bool checkBit(int mask, int pos) { return (bool)(mask & (1<<pos)); }

int w[15], n, m, q, counter[5005][2];
vector<ii> vp1[5005];

int bin2Dec(string str)
{
    int p = 1, dec = 0;
    for(int i = n - 1; i >= 0; i--) {
        dec += (str[i] - 48) * p;
        p <<= 1;
    }

    return dec;
}

int main()
{
    //ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    scanf("%d %d %d", &n, &m, &q);
    for(int i = 0; i < n; i++)
        scanf("%d", &w[i]);

    char str[30];

    for(int i = 0; i < m; i++) {
        scanf("%s", str);
        counter[bin2Dec(str)][0]++;
    }

    vector<ii> vp;

    int val;

    for(int i = 0; i < (1<<n); i++) {
        vp1[i].clear();
        for(int j = 0; j < (1<<n); j++) {
            int sum = 0, flag = 0;
            for(int k = 0; k < n; k++) {
                sum += w[n-k-1] * ((i & (1 << k)) == (j & (1 << k)));
            }
            vp1[i].pb(mk(sum, counter[j][0]));
        }
        sort(vp1[i].begin(), vp1[i].end());
        for(int j = 1; j < vp1[i].size(); j++) {
            vp1[i][j].ss += vp1[i][j-1].ss;
        }
    }


    for(int i = 0; i < q; i++) {
        scanf("%s %d", str, &val);
        int x = bin2Dec(str);
        int idx = lower_bound(vp1[x].begin(), vp1[x].end(), mk(val, INF)) - vp1[x].begin();
        printf("%d\n", vp1[x][idx-1].ss);
    }

    return 0;
}


