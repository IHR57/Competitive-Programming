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
 
ll dp[100];
 
int bruteForce(int k)
{
    int cnt = 0;
    for(int i = 0; i <= k; i++) {
        int x = 0, tk = k;
        while(tk) {
            x++;
            tk /= 2;
        }
        for(int j = 0; j < x; j++) {
            if(i) {
                if((check(i, j) && !check(i-1, j)) || (!check(i, j) && check(i - 1, j)))
                   cnt++;
            }
        }
    }
 
    return cnt;
}
 
int cntBit(ll n)
{
    int cnt = 0;
    while(n) {
        n /= 2;
        cnt++;
    }
 
    return cnt - 1;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
    //for(int i = 1; i <= 50; i++){
    //    cout<<i<<" "<<bruteForce(i)<<endl;
    //}
    dp[0] = 0, dp[1] = 1;
    for(int i = 2; i <= 63; i++)
        dp[i] = dp[i-1] + ((1LL<<i) - 1);
 
    int test;
    ll n;
 
    cin>>test;
 
    while(test--) {
        cin>>n;
        ll tn = n;
        ll ans = 0;
        while(n != 0) {
            int bit = cntBit(n);
            ans += dp[bit];
            n -= (1LL<<bit);
            ans += bit + 1;
        }
        cout<<ans<<endl;
    }
    return 0;
}