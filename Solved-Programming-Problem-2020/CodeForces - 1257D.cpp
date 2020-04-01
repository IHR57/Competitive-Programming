//Date: 23/03/2020
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
    
    int test, n;

    cin>>test;

    while(test--){
        cin>>n;
        int maxH = 0, maxM = 0;
        for(int i = 0; i < n; i++){
            cin>>arr[i];
            maxM = max(maxM, arr[i]);
        }
        int m, u, v;
        cin>>m;
        vector<ii> vp;

        for(int i = 0; i < m; i++){
            cin>>u>>v;
            vp.pb(mk(u, v));
            maxH = max(maxH, u);
        }

        if(maxM > maxH){
            cout<<-1<<endl;
            continue;
        }

        sort(vp.begin(), vp.end());

        for(int i = m - 2; i >= 0; i--){
            vp[i].second = max(vp[i].second, vp[i+1].second);
        }


        int prevIdx = -1, prevCnt, counter = 1, ans = 0, mx = 0, flag = 0;
        for(int i = 0; i < n; ){
            mx = arr[i];
            int j = i;
            while(j < n){
                mx = max(mx, arr[j]);
                int idx = lower_bound(vp.begin(), vp.end(), mk(mx, 0)) - vp.begin();
                idx = (idx < m) ? idx : 0;
                if((j - i + 1) <= vp[idx].second){
                    j++;
                }
                else
                    break;
            }
            ans++;
            if(j == i){
                flag = 1;
                break;
            }
            i = j;
        }

        (flag) ? cout<<-1<<endl : cout<<ans<<endl;

    }

    return 0;

}
