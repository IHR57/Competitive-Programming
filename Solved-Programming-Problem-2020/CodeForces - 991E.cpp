//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define mem(a, b) (memset(a, b, sizeof(a)))
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define INF 2147483647
#define MOD 1000000009
#define MAX 200005
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> pii;
typedef vector<ii> vii;
typedef priority_queue<int,vector<int>,greater<int> > PQ;
 
int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

vector<int> digit;
int counter[10], temp[10];
ll dp[20][20];

unsigned long long ans = 0;

void solve(int x, int cnt)
{
    if(x >= 10) {
        ll ret = dp[cnt-1][temp[0]];
        int rem = cnt - temp[0];
        for(int i = 1; i <= 9; i++) {
            ret *= dp[rem][temp[i]];
            rem -= temp[i];
        }

        ans += ret;
        return;
    }

    if(!counter[x])
        solve(x + 1, cnt);
    else{
        for(int i = 1; i <= counter[x]; i++) {
            temp[x] = i;
            solve(x + 1, cnt + i);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    ll n;
    cin>>n;

    while(n) {
        counter[n%10]++;
        n /= 10;
    }

    dp[0][0] = 1;
    for(int i = 1; i < 20; i++) {
        dp[i][0] = dp[i][i] = 1;
        for(int j = 1; j < min(19, i); j++) {
            dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
        }
    }
    solve(0, 0);

    cout<<ans<<endl;
 
    return 0;
}