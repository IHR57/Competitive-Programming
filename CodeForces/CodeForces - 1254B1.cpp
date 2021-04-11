//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define mem(a, b) (memset(a, b, sizeof(a)))
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define INF 2147483647
#define MOD 998244353
#define MAX 200005
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> pii;
typedef vector<ii> vii;
typedef priority_queue<int,vector<int>,greater<int> > PQ;

int setBit(int mask, int pos){return mask = mask | (1<<pos);}
bool checkBit(int mask, int pos){return (bool)(mask & (1<<pos));}

int arr[MAX];
vector<int> v;

int main()
{
    //ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n;

    scanf("%d", &n);
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if(arr[i] == 1) {
            cnt++;
            v.pb(i + 1);
        }
    }    

    if(cnt == 1) {
        printf("-1\n");
        return 0;
    }

    vector<int> div;
    for(int i = 1; i * i <= cnt; i++) {
        if(cnt % i == 0) {
            div.pb(i); div.pb(cnt / i);
        }
    }

    ll ans = 1e18;

    for(int i = 0; i < div.size(); i++) {
        int x = div[i];
        if(x == 1)
            continue;
        ll sum = 0;
        for(int j = 0; j < v.size(); j += x) {
            int mid = v[(2 * j + x - 1) / 2];
            for(int k = j; k < j + x; k++) {
                sum += (ll) abs(mid - v[k]);
            }
        }
        ans = min(ans, sum);
    }
    if(ans == 1e18)
        ans = 0;

    printf("%lld\n", ans);

    return 0;
}


