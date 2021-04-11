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

int arr[2*MAX];
ll cs[2*MAX][2];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n;

    cin>>n;

    for(int i = 0; i < n; i++) {
        cin>>arr[i];
        arr[i+n] = arr[i];
    }

    for(int i = 0; i < 2 * n; i++) {
        cs[i+1][0] = cs[i][0];
        cs[i+1][1] = cs[i][1];
        cs[i+1][i%2] += arr[i];
    }

    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ll temp = arr[i] + cs[i+n][(i+1)%2] - cs[i+1][(i+1)%2];
        ans = max(ans, temp);
    }

    cout<<ans<<endl;

    return 0;
}


