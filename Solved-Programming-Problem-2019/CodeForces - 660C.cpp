//Date: 12/10/19
#include <bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define pi 3.1415926535897932384
#define INF 2147483647
#define EPS 1e-8
#define MOD 1000000007
#define MAX 300005
using namespace std;
 
typedef long long ll;
typedef pair<int, int> ii;
 
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
    
    int n, k;

    cin>>n>>k;

    vector<int> v;
    int cnt = 0, maxCnt = 0, c = 0;
    v.pb(0);
    for(int i = 1; i <= n; i++){
        cin>>arr[i];
        if(!arr[i]){
            v.pb(i);
            cnt++;
        }
        if(i > 1 && arr[i] == 1 && arr[i-1] == 1){
            c++;
            maxCnt = max(c, maxCnt);
        }
        else if(arr[i] == 1){
            c = 1;
            maxCnt = max(c, maxCnt);
        }
    }
    v.pb(n+1);

    if(k == 0){
        cout<<maxCnt<<endl;
        for(int i = 1; i <= n; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        return 0;
    }
    if(cnt <= k){
        cout<<n<<endl;
        for(int i = 1; i <= n; i++){
            cout<<1<<" ";
        }
        cout<<endl;
        return 0;
    }

    int sz = v.size(), Max = 0, mx, my;
    
    for(int i = 1; i < sz - k; i++){
        int x = i + k - 1;
        int ans = (v[i] - v[i-1]) + (v[x+1] - v[x]) + (v[x] - v[i] - 1);
        if(ans > Max){
            mx = i;
            my = x;
            Max = ans;
        }
    }

    for(int i = v[mx]; i <= v[my]; i++){
        arr[i] = 1;
    }

    cout<<Max<<endl;
    for(int i = 1; i <= n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}