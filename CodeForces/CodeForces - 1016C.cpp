//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define mem(a, b) (memset(a, b, sizeof(a)))
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define INF 2147483647
#define MOD 1000000009
#define MAX 300005
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> pii;
typedef vector<ii> vii;
typedef priority_queue<int,vector<int>,greater<int> > PQ;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

ll a[MAX], b[MAX], sum[MAX];
ll cs[MAX][2];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;

    cin>>n;

    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }
    for(int i = 0; i < n; i++) {
        cin>>b[i];
    }

    ll curr = 0, ans = 0;
    for(int i = n - 1; i >= 0; i--) {
        sum[i] = sum[i+1] + a[i] + b[i];
        cs[i][0] = a[i] + b[i] * 2 * (n - i) + cs[i+1][0] + sum[i+1];
        cs[i][1] = b[i] + a[i] * 2 * (n - i) + cs[i+1][1] + sum[i+1];
    }

    for(int i = 0; i < n; i++) {
        ans = max(ans, curr + cs[i][i%2] + (2 * i - 1) * sum[i]);
        if(i % 2 == 0)
            curr += a[i] * i * 2 + b[i] * (2 * i + 1);
        else
            curr += b[i] * i * 2 + a[i] * (2 * i + 1);
    }

    ans = max(ans, curr);

    cout<<ans<<endl;

    return 0;
}
