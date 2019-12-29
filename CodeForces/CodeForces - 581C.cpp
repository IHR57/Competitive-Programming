/*
Template for vjudge.net

    Author: Iqbal Hossain Rasel
    CodeForces: The_Silent_Man
    AtCoder   : IHR57
    TopCoder  : IHR57

*/
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
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

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

vector<pair<int, int> > v;
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

    int ans = 0;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
        if(arr[i] == 100){
            ans += 10;
            continue;
        }
        int need = ((arr[i] / 10) + 1) * 10 - arr[i];
        v.pb(mp(need, arr[i]));
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < v.size(); i++){
        v[i].ss += min(k, v[i].ff);
        k -= min(v[i].ff, k);
        if(k <= 0)
            break;
    }

    if(k){
        for(int i = 0; i < v.size(); i++){
            if(v[i].ss < 100){
                int x = v[i].ss;
                v[i].ss += min(100 - v[i].ss, k);
                k -= min(100 - x, k);
                if(k <= 0)
                    break;
            }
        }
    }
    for(int i = 0; i < v.size(); i++){
        ans += (v[i].ss / 10);
    }

    cout<<ans<<endl;

    return 0;
}
