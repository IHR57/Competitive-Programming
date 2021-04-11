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

int arr[MAX], cnt[1005];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;

    cin>>n>>m;

    bool flag = false;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
        cnt[arr[i]%m]++;
        if(cnt[arr[i]%m] >= 2){
            flag = 1;
        }
    }

    if(flag){
        cout<<0<<endl;
        return 0;
    }

    ll ans = 1;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            int t = abs(arr[i] - arr[j]);
            ans = (1LL * ans * t) % m;
        }
    }

    cout<<ans<<endl;

    return 0;
}
