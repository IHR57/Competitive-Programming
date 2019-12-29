//Date: 22/09/19
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

vector<int> qb;
int dp[MAX], res[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    for(int i = 0; i < (1<<7); i++){
        int p = 1, x = 0;
        for(int j = 0; j < 7; j++){
            if(check(i, j)){
                x += p;
            }
            p *= 10;
        }
        qb.pb(x);
    }

    int n;

    cin>>n;

    for(int i = 1; i <= n; i++)
        dp[i] = INF;
    dp[0] = 1;

    res[0] = -1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < qb.size(); j++){
            if(qb[j] <= i && dp[i-qb[j]] != INF){
                if(dp[i-qb[j]] + 1 <= dp[i]){
                    dp[i] = dp[i-qb[j]] + 1;
                    res[i] = i - qb[j];
                }
            }
        }
    }

    cout<<dp[n] - 1<<endl;
    int x = n;
    while(res[x] != -1){
        cout<<(x - res[x])<<endl;
        x = res[x];
    }

    return 0;
}