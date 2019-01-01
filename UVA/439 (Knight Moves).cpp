#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#define MAX 10
using namespace std;

typedef pair<int, int> pii;

int fx[] = {-1, -2, -2, -1, 1, 2, 2, 1};        //direction array
int fy[] = {-2, -1, 1, 2, 2, 1, -1, -2};

int visited[MAX][MAX], dist[MAX][MAX];
const int inf = 1<<28;

int breadthFirst(int sx, int sy, int dx, int dy)
{
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            visited[i][j] = 0;
            dist[i][j] = inf;
        }
    }

    queue<pii> q;

    q.push(pii(sx, sy));

    dist[sx][sy] = 0;
    visited[sx][sy] = 1;

    while(!q.empty()){
        pii top = q.front();
        q.pop();

        for(int k = 0; k < 8; k++){     //checking all the possible move
            int tx = top.first + fx[k];
            int ty = top.second + fy[k];

            //check valid position
            if(tx >= 0 && tx < 8 && ty >= 0 && ty < 8 && visited[tx][ty] == 0){
                visited[tx][ty] = 1;
                dist[tx][ty] = dist[top.first][top.second] + 1;
                q.push(pii(tx, ty));
            }
        }
    }

    return dist[dx][dy];
}

int main()
{
    char str1[20], str2[20];
    int r1, c1, r2, c2;

    while(cin>>str1>>str2){
        r1 = str1[0] - 'a';
        c1 = (str1[1] - 48) - 1;
        r2 = str2[0] - 'a';
        c2 = (str2[1] - 48) - 1;
        //cout<<r1<<" "<<c1<<" "<<r2<<" "<<c2<<endl;
        int result = breadthFirst(r1, c1, r2, c2);

        cout<<"To get from "<<str1<<" to "<<str2<<" takes "<<result<<" knight moves."<<endl;
    }

    return 0;
}
