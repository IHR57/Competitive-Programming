//Date: 11/03/2020
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
#define MAX 200005
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int arr[MAX], n, cs[MAX][2];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int test;

    cin>>test;

    while(test--){
        cin>>n;

        map<int, int> mp; 

        mp[0] = 0;
        int t1 = 0, t2 = 0, diff = 0;
        for(int i = 0; i < 2 * n; i++){
            cin>>arr[i];
            (arr[i] == 1) ? t1++ : t2++;
        }

        int ans = 1<<28;
        int d = t1 - t2;

        for(int i = n; i < 2 * n; i++){
            (arr[i] == 1) ? diff++ : diff--;
            if(!mp.count(diff)){
                mp[diff] = i - n + 1;
            }
        }

        diff = 0;
        for(int i = n - 1; i >= 0; i--){
            (arr[i] == 1) ? diff++ : diff--;
            if(mp.count(d - diff)){
                ans = min(ans, n - i + mp[d-diff]);
            }
        }

        if(mp.count(d)){
            ans = min(ans, mp[d]);
        }
        cout<<ans<<endl;

    }

    return 0;
}
