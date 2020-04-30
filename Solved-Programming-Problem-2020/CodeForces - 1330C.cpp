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
#define MAX 100005
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> pii;
typedef vector<ii> vii;
typedef priority_queue<int,vector<int>,greater<int> > PQ;
 
int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}
 
int arr[MAX],  ans[MAX];
ll cs[MAX];
 
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif
 
    int n, m;
    bool flag = true;
 
    cin>>n>>m;
 
    ll sum = 0;
    for(int i = 1; i <= m; i++){
        cin>>arr[i];
        sum += (ll) arr[i];
        if(arr[i] + i - 1> n){
        	flag = false;
        }
    }
    if(!flag){
    	cout<<-1<<endl;
    	return 0;
    }
 
    if(sum < n){
        cout<<-1<<endl;
        return 0;
    }
 
 
    for(int i = m; i >= 1; i--){
    	cs[i] = cs[i+1] + arr[i];
    }
 
    for(int i = 1; i <= m; i++){
    	ll ans = max((ll) i, n - cs[i] + 1);
    	cout<<ans<<" ";
    }
    cout<<endl;
 
    return 0;
}