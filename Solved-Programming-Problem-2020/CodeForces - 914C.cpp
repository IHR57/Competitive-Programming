/*
Template for vjudge.net

    Author: Iqbal Hossain Rasel
    CodeForces: Psychedelic
    AtCoder   : IHR57
    TopCoder  : IHR57

*/
#include <bits/stdc++.h>
#define mem(a, b) (memset(a, b, sizeof(a)))
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define INF 2147483647
#define MOD 1000000007
#define MAX 2005
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> pii;
typedef vector<ii> vii;
typedef priority_queue<int,vector<int>,greater<int> > PQ;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int needStep[1100];
int dp[1005][2][1005], k, n;
string str;

int solve(int pos, int isSmall, int cnt)
{
    if(pos >= n) {
        return needStep[cnt] == k - 1;
    }

    if(dp[pos][isSmall][cnt] != -1)
        return dp[pos][isSmall][cnt];

    int last = isSmall ? 1 : (str[pos]-48);
    
    int ret = 0;
    for(int i = 0; i <= last; i++) {
        ret += solve(pos + 1, isSmall | i < (str[pos]-48), cnt + (i == 1)) % MOD;
        ret %= MOD;
    }

    return dp[pos][isSmall][cnt] = ret;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    needStep[0] = -2;
    needStep[1] = 0;

    vector<int> temp, v;
    for(int i = 2; i <= 1000; i <<= 1) {
        needStep[i] = 1;
        v.pb(i);
    }
    while(true) {
        bool flag = true;
        for(int i = 2; i <= 1000; i++) {
            for(int j = 0; j < v.size(); j++){
                if(v[j] <= 10) {
                    if(__builtin_popcount(i) == v[j]){
                        needStep[i] = needStep[v[j]] + 1;
                        temp.pb(i);
                        flag = false;
                        break;
                    }
                }
            }
        }
        if(flag) 
            break;
        v = temp;
        temp.clear();
    }

    mem(dp, -1);

    cin>>str;
    cin>>k;

    n = str.size();
    int res = solve(0, 0, 0);

    if(k == 0)
        res = 1;
    if(k == 1) {
        res = (res - 1 + MOD) % MOD;
    }

    cout<<res%MOD<<endl;
}