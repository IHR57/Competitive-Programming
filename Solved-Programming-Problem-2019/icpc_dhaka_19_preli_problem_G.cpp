//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define mem(a, b) (memset(a, b, sizeof(a)))
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define INF 2147483647
#define MOD 1000000007
#define MAX 100005
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> pii;
typedef vector<ii> vii;
typedef priority_queue<int,vector<int>,greater<int> > PQ;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int phi[10000005];
long long dp[10000005];
bool mark[10000005];

void sievephi()
{
    int i, j;
    int n = 10000005;
    for(int i = 1; i <= n; i++)
        phi[i] = i;

    phi[1] = 1;
    mark[1] = 1;

    for(int i = 2; i <= n; i++){
        if(!mark[i]){
            for(int j = i; j <= n; j += i){
                mark[j] = 1;
                phi[j] = phi[j] / i * (i - 1);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    sievephi();
    dp[0] = phi[0];
    for(int i = 1; i < 10000005; i++){
        dp[i] = dp[i-1] + phi[i];
    }

//    cout<<dp[0]<<" "<<dp[1]<<" "<<dp[2]<<" "<<dp[3]<<" "<<dp[4]<<endl;
    int test, caseno = 1;

    scanf("%d", &test);
    int n;
    ll p;
    while(test--){
        scanf("%d %lld", &n, &p);
        ll low = 1, high = n, mid, ans = -1;
        while(low <= high){
            mid = (low + high + 1) >> 1;
            if(dp[n/mid] >= p){
                low = mid + 1;
                ans = mid;
            }
            else{
                high = mid - 1;
            }
        }
        printf("Case %d: %lld\n", caseno++, ans);
    }
    return 0;
}
