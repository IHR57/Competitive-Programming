//Date: 02/01/20
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
typedef pair<int, int> ii;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

char grid[MAX][MAX];
int csr[MAX][MAX], csc[MAX][MAX], vis[MAX][MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n, m;

    cin>>n>>m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>grid[i][j];
            if(grid[i][j] == '*'){
                csc[i+1][j+1] = csc[i][j+1] + 1;
                csr[i+1][j+1] = csr[i+1][j] + 1;
            }
            else{
                csc[i+1][j+1] = csc[i][j+1];
                csr[i+1][j+1] = csr[i+1][j];
            }
        }
    }
    
    vector<pair<ii, int> > vp;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(grid[i-1][j-1] == '*'){
                int mn = min(m - j, j - 1);
                mn = min(mn, min(n - i, i - 1));
                int low = 1, high = mn, mid, ans = -1;
                while(low <= high){
                    mid = (low + high + 1) >> 1;
                    int temp = 2 * mid + 1;
                    if(csc[i+mid][j] - csc[i-mid-1][j] == temp && csr[i][j+mid] - csr[i][j-mid-1] == temp){
                        ans = mid;
                        low = mid + 1;
                    }
                    else{
                        high = mid - 1;
                    }
                }
                if(ans != -1){
                    vp.pb(mk(mk(i, j), ans));
                    for(int k = i - ans; k <= i + ans; k++){
                        vis[k][j] = 1;
                    }
                    for(int k = j - ans; k <= j + ans; k++){
                        vis[i][k] = 1;
                    }
                }
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(grid[i-1][j-1] == '*' && !vis[i][j]){
                cout<<-1<<endl;
                return 0;
            }
        }
    }

    cout<<vp.size()<<endl;
    for(int i = 0; i < vp.size(); i++){
        cout<<vp[i].ff.ff<<" "<<vp[i].ff.ss<<" "<<vp[i].ss<<endl;
    }

    return 0;
}