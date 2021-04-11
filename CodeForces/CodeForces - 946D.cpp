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

const int inf = 1<<25;

int minHour[505][505];
int dp[505][505], dp2[505][505], cnt[505];
int n, m, k;
vector<int> t;

int solve(int pos, int taken)
{
    if(pos >= n)
        return 0;
    if(dp[pos][taken] != -1)
        return dp[pos][taken];

    int ret = INF;
    for(int i = 0; i <= cnt[pos]; i++) {
        if(taken - i >= 0) {
            ret = min(ret, minHour[pos][i] + solve(pos + 1, taken - i));
        }
    }

    return dp[pos][taken] = ret;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string str;

    cin>>n>>m>>k;

    for(int i = 0; i < n; i++) {
        cin>>str;
        vector<int> v;
        t.clear();
        for(int j = 0; j < m; j++){
            if(str[j] == '1')
                v.pb(j);
        }
        cnt[i] = v.size();

        vector<int> cs(cnt[i], 0);
        int sum = 0;
        for(int j = 1; j < v.size(); j++) {
            t.pb(v[j] - v[j-1]);
            cs[j] = cs[j-1] + t.back();
            sum += t.back();
        }

        int idx = 1;

        for(int j = 0; j <= cnt[i]; j++)
            minHour[i][j] = inf;

        int Sz = t.size() - 1;
        for(int x = 0; x < t.size(); x++) {
            for(int y = x; y < t.size(); y++) {
                minHour[i][x + abs(Sz - y)] = min(minHour[i][x+abs(Sz-y)], cs[y+1] - cs[x] + 1);
            }
        }
        if(v.size() >= 1)
            minHour[i][v.size()-1] = 1;
        minHour[i][v.size()] = 0;
    }


    memset(dp, -1, sizeof(dp));
    int res = solve(0, k);

    cout<<res<<endl;

    return 0;
}
