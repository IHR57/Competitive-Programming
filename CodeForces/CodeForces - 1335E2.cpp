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

int arr[MAX];

int main()
{
    
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int test, n;

    scanf("%d",  &test);

    while(test--) {
        scanf("%d", &n);

        vector<vector<int> > vp(201);
        vector<vector<int> > cnt(201, vector<int>(n + 1));

        for(int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
            for(int j = 1; j <= 200; j++)
                cnt[j][i+1] = cnt[j][i];
            cnt[arr[i]][i+1]++;
            vp[arr[i]].pb(i);
        }

        int ans = 0;
        for(int i = 1; i <= 200; i++) {
            int k = vp[i].size();
            ans = max(ans, k);

            for(int j = 0; j < (k / 2); j++) {
                int l = vp[i][j] + 1;
                int r = vp[i][k-j-1] - 1;
                for(int x = 1; x <= 200; x++) {
                    int tt = cnt[x][r+1] - cnt[x][l];
                    ans = max(ans, tt + (j + 1) * 2);
                }
            }
        }

        printf("%d\n", ans);
    }


    return 0;
}