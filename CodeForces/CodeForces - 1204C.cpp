//Date: 12/03/2020
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
#define MAX 105
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int arr[1000005], n, cs[MAX][2], dist[MAX][MAX];
const int inf = 1<<28;

void floyd()
{
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    string str;

    cin>>n;

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            dist[i][j] = inf;
        }
        dist[i][i] = 0;
    }

    for(int i = 0; i < n; i++){
        cin>>str;
        for(int j = 0; j < n; j++){
            if(str[j] == '1'){
                dist[i+1][j+1] = 1;
            }
        }
    }

    floyd();

    int m;

    cin>>m;

    for(int i = 0; i < m; i++){
        cin>>arr[i];
    }

    vector<ii> res;
    res.pb(mk(arr[0], 0));

    for(int i = 1; i < m; i++){
        int d = dist[res.back().ff][arr[i]];
        int dt = i - res.back().ss;
        if(d < dt){
            res.pb(mk(arr[i-1], i - 1));
        }
    }
    res.pb(mk(arr[m-1], 0));

    cout<<res.size()<<endl;
    for(int i = 0; i < res.size(); i++)
        cout<<res[i].ff<<" ";
    cout<<endl;

    return 0;
}
