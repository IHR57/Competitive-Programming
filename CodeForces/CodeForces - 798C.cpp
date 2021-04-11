//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> pii;
typedef priority_queue<int,vector<int>,greater<int> > PQ;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int setBit(int mask, int pos) { return mask = mask | (1<<pos); }
bool checkBit(int mask, int pos) { return (bool)(mask & (1<<pos)); }

int arr[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n;

    cin>>n;

    int g = 0;
    for(int i = 0; i < n; i++) {
        cin>>arr[i];
        g = __gcd(g, arr[i]);
    }

    if(g > 1) {
        cout<<"YES"<<endl;
        cout<<"0"<<endl;

        return 0;
    }

    int cnt = 0, ans = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] & 1)
            cnt++;
        else {
            ans += cnt / 2;
            if(cnt & 1)
                ans += 2;
            cnt = 0;
        }
    }

    ans += cnt / 2;
    if(cnt & 1)
        ans += 2;

    cout<<"YES"<<endl;
    cout<<ans<<endl;


    return 0;
}


