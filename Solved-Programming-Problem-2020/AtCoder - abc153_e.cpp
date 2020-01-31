//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define mem(a, b) (memset(a, b, sizeof(a)))
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define INF 100000000
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

int dp[10005][1005];
int a[1005], b[1005], h;
int n;

int solve(int amnt, int pos)
{
    if(pos >= n && amnt < h)
        return INF;
    if(amnt >= h)
        return 0;
    if(dp[amnt][pos] != -1)
        return dp[amnt][pos];

    int ret = INF;
    ret = min(ret, b[pos] + solve(amnt + a[pos], pos));
    ret = min(ret, solve(amnt, pos + 1));
    ret = min(ret, b[pos] + solve(amnt + a[pos], pos + 1));

    return dp[amnt][pos] = ret;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin>>h>>n;

    for(int i = 0; i < n; i++){
        cin>>a[i]>>b[i];
    }

    memset(dp, -1, sizeof(dp));
    int res = solve(0, 0);

    cout<<res<<endl;

    return 0;
}
