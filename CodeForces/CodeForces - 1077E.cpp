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

int n, m, arr[MAX];
vector<int> carr;

int cntBit(int x)
{
    int cnt = 0;
    while(x) {
        x >>= 1;
        cnt++;
    }

    return cnt - 1;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    cin>>n;

    map<int, int> mp;

    for(int i = 0; i < n; i++) {
        cin>>arr[i];
        mp[arr[i]]++;
    }

    sort(arr, arr + n);
    carr.pb(mp[arr[0]]);

    for(int i = 1; i < n; i++) {
        if(arr[i] != arr[i-1]) {
            carr.pb(mp[arr[i]]);
        }
    }

    sort(carr.begin(), carr.end());
    reverse(carr.begin(), carr.end());

    int ans = 0;

    for(int i = carr[0]; i >= 1; i--) {
        int tans = i;
        int tt = i;
        if((i & 1)) {
            ans = max(ans, tans);
            continue;
        }
        for(int j = 1; j < carr.size();j++) {
            if(carr[j] >= (tt >> 1)) {
                tans += (tt >> 1);
                tt >>= 1;
                if(tt & 1) {
                    break;
                }
            }
            else
                break;
        }

        ans = max(ans, tans);
    }

    cout<<ans<<endl;

    return 0;
}


