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

int arr[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int test, odd, even;

    cin>>test;

    while(test--){
        int n, m;
        odd = 0, even = 0;
        cin>>n;
        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }
        cin>>m;
        for(int i = 0; i < m; i++){
            int x;
            cin>>x;
            if(x & 1)
                odd++;
            else
                even++;
        }

        ll ans = 0;
        for(int i = 0; i < n; i++){
            if(arr[i] & 1){
                ans += (ll) odd;
            }
            else{
                ans += (ll) even;
            }
        }

        cout<<ans<<endl;
    }

    return 0;
}
