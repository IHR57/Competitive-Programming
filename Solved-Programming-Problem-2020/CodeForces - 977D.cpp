//Date: 01/02/2020
#include <bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define pi 3.1415926535897932384
#define INF 2147483647
#define EPS 1e-8
#define MAX 200005
using namespace std;
 
typedef long long ll;
typedef pair<int, int> ii;
 
int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

ll arr[105];
ll ans[105];
map<ll, int> mp;

int cnt;

void check(ll x)
{
    ans[cnt] = x;
    cnt++;
    if(mp.count(x * 2) == 0 && x % 3 == 0 && mp.count(x/3) == 0)
        return;
    if(mp.count(x * 2) && x % 3 == 0 && mp.count(x / 3)){
        return;
    }
    if(mp.count(x * 2)){
        mp[x*2]--;
        check(x*2);
    }
    else if(x % 3 == 0 && mp.count(x/3)){
        mp[x/3]--;
        check(x/3);
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n;

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    int idx;
    for(int i = 0; i < n; i++){
        mp.clear();
        cnt = 0;
        for(int j = 0; j < n; j++){
            mp[arr[j]]++;
        }
        mp[arr[i]]--;
        check(arr[i]);
        if(cnt == n){
            for(int j = 0; j < n; j++){
                cout<<ans[j]<<" ";
            }
            cout<<endl;
        }
    }

    return 0;
}