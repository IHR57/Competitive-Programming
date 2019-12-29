//Date: 22/09/19
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
#define MAX 505
using namespace std;
 
typedef unsigned long long ll;
typedef pair<int, int> ii;
 
int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int grid[MAX][MAX];
int cs[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, m, q;

    cin>>n>>m>>q;
    for(int i = 1; i <= n; i++){
        int k = 0;
        for(int j = 1; j <= m; j++){
            cin>>grid[i][j];
            if(grid[i][j] == 1){
                k++;
                cs[i] = max(cs[i], k);
            }
            else
                k = 0;
        }
        //cout<<cs[i]<<endl;
    }

    int x, y;

    for(int i = 0; i < q; i++){
        cin>>x>>y;
        grid[x][y] = !grid[x][y];
        int k = 0;
        cs[x] = 0;
        for(int j = 1; j <= m; j++){
            if(grid[x][j] == 1){
                k++;
                cs[x] = max(cs[x], k);
            }
            else
                k = 0;
        }
        int Max = 0;
        for(int j = 1; j <= n; j++){
            Max = max(Max, cs[j]);
        }

        cout<<Max<<endl;
    }

    return 0;
}