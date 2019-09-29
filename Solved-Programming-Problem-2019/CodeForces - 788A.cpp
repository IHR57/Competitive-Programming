//Date: 27/09/19
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
 
typedef long long ll;
typedef pair<int, int> ii;
 
int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int arr[MAX], n;

ll solve()
{
    ll prefSum = 0, Max = 0;
    for(int i = 0; i < n - 1; i++){
        prefSum += (ll) arr[i];
        Max = max(Max, prefSum);
        if(prefSum < 0)
            prefSum = 0;
    }
    return Max;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    for(int i = 0; i < n - 1; i++){
        arr[i] = abs(arr[i] - arr[i+1]);
        if(i & 1)
            arr[i] *= -1;
    }
    ll ans = solve();
    for(int i = 0; i < n - 1; i++)
        arr[i] *= -1;

    ans = max(ans, solve());

    cout<<ans<<endl;

    return 0;
}