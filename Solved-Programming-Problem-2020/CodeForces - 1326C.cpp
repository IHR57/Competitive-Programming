//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define mem(a, b) (memset(a, b, sizeof(a)))
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define INF 2147483647
#define MOD 998244353
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

int p[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;

    cin>>n>>k;

    ll ans = 1;

    for(int i = 0; i < n; i++){
        cin>>p[i];
    }

    ll sum = (1LL * n * (n + 1)) / 2;
    ll x = (n - k);
    sum -= (1LL * x * (x + 1)) / 2;

    int prev = -1;

    for(int i = 0; i < n; i++){
        if(p[i] > (n - k)){
            if(prev != -1){
                ans = (ans * (i - prev)) % MOD;
            }
            prev = i;
        }
    }

    cout<<sum<<" "<<ans % MOD<<endl;


    return 0;
}
