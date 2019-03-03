//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 55
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int cell[MAX][MAX], visited[MAX][MAX], mem[MAX][MAX];
int dx, dy;
vector<pii> vis, notVis;
int fx[]= {-1, 1, 0, 0 };
int fy[]= { 0, 0, -1, 1 };
const int inf = 1<<28;
int n;

bool bfs(int sx, int sy)
{
    visited[sx][sy] = 1;
    queue<pii> q;
    q.push(make_pair(sx, sy));

    while(!q.empty()){
        pii u = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){
            int tx = u.first + fx[i];
            int ty = u.second + fy[i];
            if(tx >= 0 && tx < n && ty >= 0 && ty < n && !visited[tx][ty] && cell[tx][ty] != -1){
                visited[tx][ty] = 1;
                q.push(make_pair(tx, ty));
            }
        }
    }

    return visited[dx][dy];
}

int calDist(int a, int b, int c, int d)
{
    return ((a - c) * (a - c)) + ((b - d) * (b - d));
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int sx, sy;
    char str[MAX];

    cin>>n;
    cin>>sx>>sy;
    cin>>dx>>dy;

    sx--, sy--;
    dx--, dy--;

    for(int i = 0; i < n; i++){
        cin>>str;
        for(int j = 0; j < n; j++){
            if(str[j] == '1')
                cell[i][j] = -1;
            else{
                cell[i][j] = 0;
            }
        }
    }

    bool res = bfs(sx, sy);
    if(res == true){
        cout<<0<<endl;
        return 0;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(cell[i][j] == 0 && visited[i][j]){
                vis.push_back(make_pair(i, j));
            }
            else if(cell[i][j] == 0 && !visited[i][j]){
                notVis.push_back(make_pair(i, j));
            }
        }
    }

    for(int i = 0; i < notVis.size(); i++){
        memset(visited, 0, sizeof(visited));
        bool temp = bfs(notVis[i].first, notVis[i].second);
        if(temp == true){
            mem[notVis[i].first][notVis[i].second] = 1;
        }
    }
    int Min = inf;

    for(int i = 0; i < vis.size(); i++){
        for(int j = 0; j < notVis.size(); j++){
            //cout<<vis[i].first<<" "<<vis[i].second<<" "<<notVis[j].first<<" "<<notVis[j].second<<endl;
            int result;
            if(mem[notVis[j].first][notVis[j].second] == 1){
                result = calDist(vis[i].first, vis[i].second, notVis[j].first, notVis[j].second);
                Min = min(result, Min);
            }
            //cout<<result<<endl;;
        }
    }

    cout<<Min<<endl;

    return 0;
}
