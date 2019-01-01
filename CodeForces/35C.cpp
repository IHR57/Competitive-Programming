#include <bits/stdc++.h>
#define MAX 2005
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int fx[] = {0, 0, 1, -1};
int fy[] = {1, -1, 0, 0};

int dist[MAX][MAX], visited[MAX][MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int row, col, k, x, y;

    cin>>row>>col;
    cin>>k;

    queue<pii> q;

    for(int i = 0; i < k; i++){
        cin>>x>>y;
        x--, y--;
        visited[x][y] = 1;
        q.push(make_pair(x, y));
        dist[x][y] = 0;
    }

    while(!q.empty()){
        pii u = q.front();
        q.pop();

        for(int k = 0; k < 4; k++){
            int tx = u.first + fx[k];
            int ty = u.second + fy[k];
            if(tx >= 0 && tx < row && ty >= 0 && ty < col && !visited[tx][ty]){
                dist[tx][ty] = dist[u.first][u.second] + 1;
                visited[tx][ty] = 1;
                q.push(make_pair(tx, ty));
            }
        }
    }

    int Max = -1;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(dist[i][j] > Max){
                Max = dist[i][j];
                x = i + 1;
                y = j + 1;
            }
        }
    }

    cout<<x<<" "<<y<<endl;

    return 0;
}
