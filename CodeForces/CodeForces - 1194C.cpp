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

int cnts[30], cntt[30], cntp[30], req[30];
int dp[105][105];
string s, t, p;

int solve(int i, int j)
{
    if(i >= s.size() || j >= t.size())
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    if(s[i] == t[j]){
        dp[i][j] = 1 + solve(i + 1, j + 1);
    }
    else{
        dp[i][j] = max(solve(i + 1, j), solve(i, j + 1));
    }
    return dp[i][j];
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int test;

    cin>>test;
    while(test--){
        cin>>s;
        cin>>t;
        cin>>p;

        mem(cnts, 0); mem(cntt, 0); mem(cntp, 0); mem(req, 0);
        mem(dp, -1);

        for(int i = 0; i < s.size(); i++)
            cnts[s[i]-'a']++;
        for(int i = 0; i < t.size(); i++)
            cntt[t[i]-'a']++;
        for(int i = 0; i < p.size(); i++)
            cntp[p[i]-'a']++;

        bool flag = true;
        for(int i = 0; i < 26; i++){
            if(cnts[i] > cntt[i]){
                flag = false;
                break;
            }
            req[i] = cntt[i] - cnts[i];
        }

        for(int i = 0; i < 26; i++){
            if(req[i] > cntp[i]){
                flag = false;
                break;
            }
        }
        int res = solve(0, 0);
        int len1 = s.size(), len2 = t.size();
        if(res < min(len1, len2))
            flag = false;
        (flag) ? cout<<"YES"<<endl : cout<<"NO"<<endl;
    }

    return 0;
}
