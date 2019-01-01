#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
#define pb push_back
#define MAX 20
using namespace std;

typedef long long lint;
typedef pair<int, int> pii;
const int inf = 1<<28;

int cell[MAX][MAX], dist[MAX][MAX];
int visited[MAX][MAX], n;
int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};

int breadthFirst(int sx, int sy, int dx, int dy)
{
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++)
            dist[i][j] = inf;
    }
    memset(visited, 0, sizeof(visited));

    queue<pii>q;
    q.push(pii(sx, sy));
    dist[sx][sy] = 0;
    visited[sx][sy] = 1;

    while(!q.empty()){
        pii u = q.front();
        q.pop();

        for(int k = 0; k < 4; k++){
            int tx = u.first + fx[k];
            int ty = u.second + fy[k];

            if(tx >= 0 && tx < n && ty >= 0 && ty < n && !visited[tx][ty] && cell[tx][ty] != -1){
                if(cell[tx][ty] == 1){
                    //cell[tx][ty] = -1;
                    if(tx == dx && ty == dy){
                        dist[tx][ty] = dist[u.first][u.second] + 1;
                        return dist[tx][ty];
                    }
                    else
                        continue;
                }
                else{
                    visited[tx][ty] = 1;
                    dist[tx][ty] = dist[u.first][u.second] + 1;
                    q.push(pii(tx, ty));
                }

            }
        }
    }

    return dist[dx][dy];
}

int main()
{
    //freopen("output.txt", "w", stdout);

    int test, caseNo = 1;
    char str[100];

    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);
        int count = 0;
        pii alphabet[200];
        for(int i = 0; i < n; i++){
            scanf("%s", str);
            for(int j = 0; j < n; j++){
                if(str[j] >= 'A' && str[j] <= 'Z'){
                    alphabet[str[j]] = pii(i, j);
                    cell[i][j] = 1;
                    count++;            //number of character [A-Z]
                }
                else if(str[j] == '#')
                    cell[i][j] = -1;
                else
                    cell[i][j] = 0;
            }
        }

        int result = 0, flag = 0;
        for(int i = 65; i < (65 + count - 1); i++){
            cell[alphabet[i].first][alphabet[i].second] = 1;
            cell[alphabet[i+1].first][alphabet[i+1].second] = 1;
            int ans = breadthFirst(alphabet[i].first, alphabet[i].second, alphabet[i + 1].first, alphabet[i+1].second);
            cell[alphabet[i].first][alphabet[i].second] = 0;
            //cout<<ans<<endl;
            //cout<<alphabet[i].first<<alphabet[i].second<<" "<<alphabet[i+1].first<<alphabet[i+1].second<<endl;
            if(ans == inf){
                flag = 1;
            }
            result += ans;
        }

        (flag == 1) ? printf("Case %d: Impossible\n", caseNo++) : printf("Case %d: %d\n", caseNo++, result);
    }

    return 0;
}
