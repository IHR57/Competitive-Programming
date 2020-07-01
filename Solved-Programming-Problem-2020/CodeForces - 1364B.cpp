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
 
    int test,n;
 
    cin>>test;
 
    while(test--) {
        cin>>n;
        for(int i = 0; i < n; i++) {
            cin>>arr[i];
        }
 
        int prev = -1;
 
        int asc = 1, dsc = 1;
        for(int i = 1; i < n; i++) {
            if(arr[i] - arr[i-1] > 0) {
                asc++;
            }
            else if(arr[i-1] - arr[i] > 0)
                dsc++;
        }
        if(asc == n || dsc == n) {
            cout<<2<<endl;
            cout<<arr[0]<<" "<<arr[n-1]<<endl;
            continue;
        }
        int par;
        vector<int> res;
        res.pb(arr[0]);
 
        if(arr[1] > arr[0])
            par = 1;
        else
            par = 2;
        for(int i = 2; i < n; i++) {
            if((arr[i] - arr[i-1]) > 0 && par == 2) {
                res.pb(arr[i-1]);
                par = 1;
            }
            else if((arr[i] - arr[i-1]) < 0 && par == 1) {
                res.pb(arr[i-1]);
                par = 2;
            }
        }
        res.pb(arr[n-1]);
 
        cout<<res.size()<<endl;
 
        for(int i = 0; i < res.size(); i++)
            cout<<res[i]<<" ";
        cout<<endl;
    }
 
    return 0;
}