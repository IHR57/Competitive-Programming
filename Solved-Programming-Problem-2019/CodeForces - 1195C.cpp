//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define mem(a, b) (memset(a, b, sizeof(a)))
#define debug (printf("PINK FLOYD:)\n"))
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define INF 2147483647
#define EPS 1e-8
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

ll dp[MAX][2];
int h1[MAX], h2[MAX], n;

ll solve(int pos, int turn)
{
    if(pos >= n)
        return 0;
    if(dp[pos][turn] != -1)
        return dp[pos][turn];
    ll ret = 0;
    if(!turn){
        ret = (ll) h1[pos] + solve(pos + 1, !turn);
        ret = max(ret, solve(pos + 1, turn));
    }
    else{
        ret = (ll) h2[pos] + solve(pos + 1, !turn);
        ret = max(ret, solve(pos + 1, turn));
    }

    return dp[pos][turn] = ret;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>h1[i];
    }
    for(int i = 0; i < n ; i++){
        cin>>h2[i];
    }

    mem(dp, -1);

    ll result = solve(0, 0);
    mem(dp, -1);
    result = max(result,  solve(0, 1));
    cout<<result<<endl;

    return 0;
}
