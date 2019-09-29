//Date: 24/09/19
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
#define MAX 1000005
using namespace std;
 
typedef unsigned long long ll;
typedef pair<int, int> ii;
 
int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int primes[80000], arr[200005], counter = 0, n, dp[200005];
bool mark[MAX];
vector<int> v[MAX];

void genSieve()
{
    int limit = sqrt(MAX + 1);
    for(int i = 4; i < MAX; i += 2)
        mark[i] = 1;
    primes[counter++] = 2;
    for(int i = 3; i < MAX; i += 2){
        if(!mark[i]){
            primes[counter++] = i;
            if(i <= limit){
                for(int j = i * i; j < MAX; j += i * 2)
                    mark[j] = 1;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifdef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int test, caseno = 1, k;
    genSieve();
    for(int i = 0; i < counter; i++){
        for(int j = primes[i]; j < MAX; j += primes[i]){
            v[j].pb(primes[i]);
        }
    }
    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &n, &k);
        for(int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
        }
        dp[0] = 0;
        map<int, int> mp;
        vector<int> idx[79000];
        int m = 1;
        for(int i = 0; i < v[arr[0]].size(); i++){
            int u = v[arr[0]][i];
            if(mp[u] == 0){
                mp[u] = m++;
            }
            idx[mp[u]].pb(0);
        }
        for(int i = 1; i < n; i++){
            dp[i] = dp[i-1] + 1;
            for(int j = 0; j < v[arr[i]].size(); j++){
                int u = v[arr[i]][j];
                if(mp[u] != 0 && idx[mp[u]].size() > 0){
                    int x = lower_bound(idx[mp[u]].begin(), idx[mp[u]].end(), i - k) - idx[mp[u]].begin();
                    if(x < idx[mp[u]].size())
                        dp[i] = min(dp[i], dp[idx[mp[u]][x]] + 1);
                }
                if(mp[u] == 0)
                    mp[u] = m++;
            }
            for(int j = 0; j < v[arr[i]].size(); j++){
                idx[mp[v[arr[i]][j]]].pb(i);
            }
        }

        printf("Case %d: %d\n", caseno++, dp[n-1]);
    }

    return 0;
}