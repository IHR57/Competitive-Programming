#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define pi 3.1415926535897932384
#define INF 2147483647
#define MOD 1000000007
#define MAX 205
using namespace std;

typedef long long ll;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int arr[MAX], vis[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int test, n, k;
    
    cin>>test;

    while(test--){
        cin>>n>>k;
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < k; i++){
            cin>>arr[i];
            vis[arr[i]] = 1;
        }

        int x = 1;
        while(true){
            bool flag = false;
            for(int i = 0; i < k; i++){
                int t = arr[i] - x;
                if(t >= 1 && !vis[t]){
                    vis[t] = 1;
                    flag = true;
                }
                t = arr[i] + x;
                if(t <= n && !vis[t]){
                    vis[t] = 1;
                    flag = true;
                }
            }
            if(!flag){
                break;
            }
            x++;
        }

        cout<<x<<endl;

    }    
    return 0;
}
