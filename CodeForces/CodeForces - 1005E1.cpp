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
#define MAX 1000005
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> pii;
typedef vector<ii> vii;
typedef priority_queue<int,vector<int>,greater<int> > PQ;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int arr[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m, idx;

    cin>>n>>m;

    for(int i = 0; i < n; i++) {
        cin>>arr[i];
        if(arr[i] == m) {
            idx = i;
        }
    }

    map<int, int> mp;
    ll ans = 1;
    int greater_m = 0, smaller_m = 0;
    for(int i = idx + 1; i < n; i++) {
        (arr[i] > m) ? greater_m++ : smaller_m++;
        mp[smaller_m - greater_m]++;
        if(smaller_m - greater_m == 0 || smaller_m - greater_m == -1)
            ans++;
    }

    greater_m = 0, smaller_m = 0;
    for(int i = idx - 1; i >= 0; i--) {
        (arr[i] > m) ? greater_m++ : smaller_m++;
        int diff = smaller_m - greater_m;
        ans += (ll) mp[-diff];
        ans += (ll) mp[-diff -1];
        if(diff == 0 || diff == -1)
            ans++;
    }


    cout<<ans<<endl;

    return 0;
}
