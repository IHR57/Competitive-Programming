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

ll dp[105][2][2][105];
int visited[105][2][2][105];
int lim, k;

vector<int> digit;
int cnt;

ll solve(int pos, int isSmall, int isStart, int value)
{
    //cout<<pos<<endl;
    if(value > k)
        return 0;
    if(pos == lim){
        if(value == k)
            return 1;
        return 0;
    }
    if(dp[pos][isSmall][isStart][value] != -1)
        return dp[pos][isSmall][isStart][value];


    int last = isSmall ? 9 : digit[pos];
    ll ret = 0;

    if(!isStart){
        for(int i = 0; i <= last; i++){
            ret += solve(pos + 1, isSmall | i < digit[pos], 0, ((i != 0) ? 1 : 0) + value);
        }
    }
    else{
        for(int i = 1; i <= last; i++){
            ret += solve(pos + 1, isSmall | i < digit[pos], 0, 1 + value);
        }
        ret += solve(pos + 1, 1, 1, 0);     //we need this call because leading zero is not allowed
    }

    return dp[pos][isSmall][isStart][value] = ret;
}


int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    string str;

    cin>>str;
    cin>>k;

    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < (int) str.size(); i++){
        digit.pb(str[i]-48);
    }

    lim = digit.size();
    ll result = solve(0, 0, 0, 0);

    cout<<result<<endl;

    return 0;
}
