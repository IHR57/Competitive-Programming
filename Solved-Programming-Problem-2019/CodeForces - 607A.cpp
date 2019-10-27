/*
Template for vjudge.net

    Author: Iqbal Hossain Rasel
    CodeForces: The_Silent_Man
    AtCoder   : IHR57
    TopCoder  : IHR57

*/
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
#define MAX 100005
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int dp[MAX];
ii d[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n;

    cin>>n;
    
    for(int i = 0; i < n; i++){
        cin>>d[i].ff>>d[i].ss;
    }
    
    sort(d, d + n);

    for(int i = 0; i < n; i++){
        int idx = lower_bound(d, d + n, mk(d[i].ff - d[i].ss, 0)) - d;
        idx--;
        if(idx < 0)
            dp[i] = 1;
        else
            dp[i] = dp[idx] + 1;
    }

    int Max = *max_element(dp, dp + n);
    cout<<(n - Max)<<endl;

    return 0;
}
