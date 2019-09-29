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
#define MAX 100005
using namespace std;
 
typedef unsigned long long ll;
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
    
    int n, goal;

    cin>>n>>goal;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    ll low = 0, high = 1e17, mid, ans;

    while(low <= high){
        mid = (low + high + 1) >> 1;
        ll cnt = 0;
        for(int i = 0; i < n; i++){
            cnt += (ll) (mid / arr[i]);
        }
        if(cnt >= goal){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    cout<<ans<<endl;

    return 0;
}