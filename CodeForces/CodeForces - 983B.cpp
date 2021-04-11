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

int dp[5005][5005], maxInRange[5005][5005];
int arr[5005], n;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin>>n;

    for(int i = 1; i <= n; i++) {
        cin>>arr[i];
        dp[i][i] = arr[i];
        maxInRange[i][i] = arr[i];
    }

    for(int i = 2; i <= n; i++) {
        int y = i, x = 1;
        for(int j = i; j <= n; j++) {
            dp[x][y] = (dp[x][y-1] ^ dp[x+1][y]);
            //cout<<"("<<x<<" "<<y<<") ->"<<dp[x][y]<<endl;
            maxInRange[x][y] = max(dp[x][y], max(maxInRange[x][y-1], maxInRange[x+1][y]));
            x++, y++;
        }
    }

    int q;
    cin>>q;

    for(int i = 0; i < q; i++) {
        int l, r;
        cin>>l>>r;
        cout<<maxInRange[l][r]<<endl;
    }

    return 0;
}
