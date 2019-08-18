#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define pi 3.1415926535897932384
#define INF 2147483647
#define MOD 1000000007
#define MAX 100005
using namespace std;

typedef long long ll;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

set<ll> s;

ll arr[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    set<int> s;
    int n, k;

    cin>>n>>k;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
        s.insert(arr[i]);
    }

    sort(arr, arr + n);
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(s.count(arr[i] + k)){
            cnt++;
        }
    }

    cout<<cnt<<endl;

    return 0;
}
