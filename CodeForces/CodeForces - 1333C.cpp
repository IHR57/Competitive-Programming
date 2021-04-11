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

    for(int i = 1; i <= n; i++) {
        cin>>arr[i];
    }

    map<ll, int> mp;
    mp[0] = 0;

    ll cs = 0, ans = 0;
    int leftIdx = -1;
    for(int i = 1; i <= n; i++) {
        cs += (ll) arr[i];
        if(!mp.count(cs)){
            if(leftIdx == -1)
                ans += (ll) i;
            else
                ans += (ll) i - leftIdx - 1;
        }
        else {
            leftIdx = max(leftIdx, mp[cs]);
            ans += (ll) i - leftIdx - 1;
        }
        mp[cs] = i;
    }

    cout<<ans<<endl;

    return 0;
}