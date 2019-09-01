//Problem ID: CodeForces - 987C (Three Displays)
//Programmer: IQBAL HOSSAIN     Description: DP
//Date: 26/08/19
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define INF 1e17
#define MOD 1000000007
#define tan(a) tan(a*PI/180)
#define MAX 200005
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

ll dp[MAX][3];
ll s[MAX], c[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n;

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>s[i];
    }
    for(int i = 0; i < n; i++){
        cin>>c[i];
    }

    for(int i = 0; i < n; i++){
        dp[i][0] = c[i];
        dp[i][1] = dp[i][2] = INF;
    }

    for(int i = n - 2; i >= 0; i--){
        for(int j = i + 1; j < n; j++){
            if(s[j] > s[i] && dp[j][0] != INF)
                dp[i][1] = min(dp[i][1], c[i] + dp[j][0]);
            if(s[j] > s[i] && dp[j][1] != INF)
                dp[i][2] = min(dp[i][2], c[i] + dp[j][1]);
        }
    }

    ll Min = 1e16;
    for(int i = 0; i < n; i++){
        Min = min(Min, dp[i][2]);
    }

    (Min == 1e16) ? cout<<-1<<endl : cout<<Min<<endl;

    return 0;
}
