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

int grid[305][305];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int test;
    int n, k;

    cin>>test;

    while(test--) {
        cin>>n>>k;
        memset(grid, 0, sizeof(grid));

        int stx = 0, sty = 0;
        int x = 0, y = 0;
        for(int i = 1; i <= k; i++) {
            grid[x][y] = 1;
            x++, y++;
            x %= n, y %= n;
            if(i % n == 0) {
                sty++;
                x = stx, y = sty;
            }
        }

        vector<int> rowSum(n + 1, 0), colSum(n + 1, 0);

        if(k % n != 0) {
            cout<<2<<endl;
        }
        else
            cout<<0<<endl;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout<<grid[i][j];
            }
            cout<<endl;
        }
    }

    return 0;
}

