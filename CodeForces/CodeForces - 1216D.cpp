//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define mem(a, b) (memset(a, b, sizeof(a)))
#define pb push_back
#define mp make_pair
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

    int n, g = 0;

    cin>>n;

    int Max = 0;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
        Max = max(Max, arr[i]);
    }

    ll ans = 0;
    for(int i = 0; i <  n; i++){
        g = __gcd(Max - arr[i], g);
    }

    for(int i = 0; i < n; i++){
        if(Max - arr[i] > 0){
            ans += (ll) ((Max - arr[i]) / g);
        }
    }

    cout<<ans<<" "<<g<<endl;

    return 0;
}
