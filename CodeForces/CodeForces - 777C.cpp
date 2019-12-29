//Date: 08/10/19
#include <bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define pi 3.1415926535897932384
#define INF 2147483647
#define EPS 1e-8
#define MOD 1000000007
#define MAX 100005
using namespace std;
 
typedef long long ll;
typedef pair<int, int> ii;
 
int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

vector<int> v[MAX];
int dp[MAX], st[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    int n, m;

    scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; i++){
        v[i].resize(m + 1);
        for(int j = 1; j <= m; j++){
            scanf("%d", &v[i][j]);
        }
    }

    for(int i = 1; i <= m; i++)
        st[i] = n;

    for(int i = n - 1; i >= 1; i--){
        for(int j = 1; j <= m; j++){
            if(v[i+1][j] < v[i][j]){
                st[j] = i;
            }
            dp[i] = max(dp[i], st[j]);
        }
    }
    dp[n] = n;

    int q, L, R;

    scanf("%d", &q);

    for(int i = 0; i < q; i++){
        scanf("%d %d", &L, &R);
        if(dp[L] >= R){
            printf("Yes\n");
        }
        else
            printf("No\n");
    }

    return 0;
}