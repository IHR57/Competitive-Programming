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

ll dp[MAX], cs[MAX];
ll arr[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;

    cin>>n>>m;

    for(int i = 1; i <= n; i++){
        cin>>arr[i];
    }

    sort(arr + 1, arr + n + 1);

    for(int i = 1; i <= n; i++){
        //cin>>arr[i];
        cs[i] = cs[i-1] + arr[i];
        if(i <= m)
            dp[i] = cs[i];
        else
            dp[i] = cs[i] + dp[i-m];
    }

    for(int i = 1; i <= n; i++){
        cout<<dp[i]<<" ";
    }
    cout<<endl;

    return 0;
}
