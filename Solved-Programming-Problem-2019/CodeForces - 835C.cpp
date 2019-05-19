#include <bits/stdc++.h>
#define MAX 105
using namespace std;

int cs[MAX][MAX][15];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q, c;
    int x1, y1, x2, y2, s, t;

    cin>>n>>q>>c;

    for(int i = 0; i < n; i++){
        cin>>x1>>y1>>s;
        cs[x1][y1][s]++;
    }

    for(int k = 0; k <= c; k++){
        for(int i = 1; i < MAX; i++){
            for(int j = 1; j < MAX; j++){
                cs[i][j][k] += cs[i-1][j][k] + cs[i][j-1][k] - cs[i-1][j-1][k];
            }
        }
    }
    for(int i = 0; i < q; i++){
        cin>>t>>x1>>y1>>x2>>y2;
        int res = 0;
        for(int k = 0; k <= c; k++){
            int x = (k + t) % (c + 1);
            int cnt = cs[x2][y2][k] - cs[x1-1][y2][k] - cs[x2][y1-1][k] + cs[x1-1][y1-1][k];
            res += (x * cnt);
        }

        cout<<res<<endl;
    }

    return 0;
}
