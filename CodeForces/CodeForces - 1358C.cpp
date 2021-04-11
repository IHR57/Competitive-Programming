//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define mem(a, b) (memset(a, b, sizeof(a)))
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define INF 2147483647
#define MOD 1000000007
#define MAX 200005
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> pii;
typedef vector<ii> vii;
typedef priority_queue<int,vector<int>,greater<int> > PQ;
 
int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}
 
int grid[50][50], n, m;
set<int> s;
 
void solve(int x, int y, int sum)
{
    if(x > n || y > m)
        return;
    if(x == n && y == m){
        s.insert(sum);
        //cout<<sum<<endl;
    }
 
    solve(x+1, y, sum + grid[x][y]);
    solve(x, y + 1, sum + grid[x][y]);
}
 
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
    /*
    for(int i = 1; i <= 20; i++) {
        int x = (i * (i + 1)) >> 1;
        int k = i;
        int val = x;
        for(int j = 1; j <= 20; j++) {
            cout<<val<<" ";
            grid[i][j] = val;
            val = val + k;
            k++;
        }
        cout<<endl;
    }
 
    n = 4, m = 3;
    solve(1, 1, 0);
 
    cout<<s.size()<<endl;
    */
    int test;
 
    cin>>test;
 
    while(test--) {
        int x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;
        int tx = abs(x2 - x1) + 1, ty = abs(y2 - y1) + 1;
        ll ans = 1 + 1LL * (ty - 1) * (tx - 1);
        cout<<ans<<endl;
    }
 
    return 0;
}