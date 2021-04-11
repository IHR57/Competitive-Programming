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

int arr[MAX], bit[MAX], n;

int get(int idx) 
{
    int cnt = 0;

    while(idx >= 0) {
        cnt += bit[idx];
        idx = (idx & (idx + 1)) - 1;
    }

    return cnt;
}

void update(int idx) 
{
    while(idx < MAX) {
        bit[idx]++;
        idx = idx | (idx + 1);
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    ll target;

    vector<ll> v;

    cin>>n>>target;

    ll sum = 0, res = 0;
    v.pb(sum);
    
    for(int i = 0; i < n; i++) {
        cin>>arr[i];
        sum += arr[i];
        v.pb(sum);
    }

    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());

    int idx = lower_bound(v.begin(), v.end(), 0LL) - v.begin();
    update(idx);

    sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
        idx = upper_bound(v.begin(), v.end(), sum - target) - v.begin();
        res += (i + 1 - get(idx - 1));

        idx = lower_bound(v.begin(), v.end(), sum) - v.begin();
        update(idx);
    }


    cout<<res<<endl;

    return 0;
}