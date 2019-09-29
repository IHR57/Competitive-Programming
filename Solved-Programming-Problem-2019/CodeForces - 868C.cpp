//Date: 24/09/19
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
#define MAX 100005
using namespace std;
 
typedef unsigned long long ll;
typedef pair<int, int> ii;
 
int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int vis[16], posSum[5];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, k, a;

    cin>>n>>k;

    for(int i = 0; i < n; i++){
        int sum = 0, p = k - 1;
        for(int j = 0; j < k; j++){
            cin>>a;
            sum += (a * (1 << p));
            p--;
        }
        vis[sum] = 1;
    }
    if(vis[0]){
        cout<<"YES"<<endl;
        return 0;
    }

    for(int i = 0; i < (1<<k); i++){
        for(int j = 0; j < (1<<k); j++){
            if(vis[i] && vis[j]){
                bool flag = true;
                memset(posSum, 0, sizeof(posSum));
                for(int x = 0; x < k; x++){
                    if(check(i, x))
                        posSum[x]++;
                    if(check(j, x))
                        posSum[x]++;
                    if(posSum[x] >= 2){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    cout<<"YES"<<endl;
                    return 0;
                }
            }
        }

    }

    cout<<"NO"<<endl;

    return 0;
}