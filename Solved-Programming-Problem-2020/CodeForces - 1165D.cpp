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
 
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int test;
 
    cin>>test;
 
    while(test--){
        int n, val;
        cin>>n;
        vector<int> arr;
 
        for(int i = 0; i < n; i++){
            cin>>val;
            arr.pb(val);
        }
 
        sort(arr.begin(), arr.end());
 
        ll x = 1LL * arr[0] * arr[n-1];
 
        vector<int> res;
        for(ll i = 2; i * i <= x; i++){
            if(x % i == 0){
                res.pb(i);
                if(x / i != i){
                    res.pb(x / i);
                }
            }
        }
 
        sort(res.begin(), res.end());
 
        if(res == arr){
            cout<<x<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
 
    return 0;
}