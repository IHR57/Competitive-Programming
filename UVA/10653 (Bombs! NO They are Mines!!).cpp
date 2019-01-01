#include <bits//stdc++.h>
#define MAX 1005
using namespace std;

int visited[MAX][MAX], cell[MAX][MAX];
int dist[MAX][MAX], row, col;
int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};

struct PII
{
    int u, v;
};

const int INF = 1 << 28;

int breadthFirst(int sx, int sy, int dx, int dy)
{
    memset(visited, 0, sizeof(visited));
    memset(dist, INF, sizeof(dist));

    visited[sx][sy] = 1;
    dist[sx][sy] = 0;

    queue<PII>q;

    PII pi;
    pi.u = sx; pi.v = sy;

    q.push(pi);     //pushing source index

    while(!q.empty()){
        PII pq;
        pq = q.front();
        q.pop();

        for(int k = 0; k < 4; k++){     //check all direction it can move
            int tx = pq.u + fx[k];
            int ty = pq.v + fy[k];
            //check for valid tx and ty
            if(tx >= 0 && tx < row && ty >= 0 && ty < col && cell[tx][ty] != -1 && visited[tx][ty] == 0){
                visited[tx][ty] = 1;
                dist[tx][ty] = dist[pq.u][pq.v] + 1;
                if(tx == dx && ty == dy)
                    return dist[tx][ty];        //if we reached destination
                PII get;
                get.u = tx;     get.v = ty;
                q.push(get);        //pushing new pair in queue
            }
        }
    }

    return dist[dx][dy];
}

int main()
{
    int n, row_num, bomb, position;
    int s1, s2, d1, d2;

    while(cin>>row>>col){
        memset(cell, 1, sizeof(cell));      //initially set all cell are 1
        if(row == 0 && col == 0)
            break;
        cin>>n;

        for(int i = 0; i < n; i++){
            cin>>row_num>>bomb;
            for(int j = 0; j < bomb; j++){
                cin>>position;
                cell[row_num][position] = -1;       //-1 indicates that the cell is block
            }
        }
        cin>>s1>>s2;        //source
        cin>>d1>>d2;        //destination

        int result = breadthFirst(s1, s2, d1, d2);

        cout<<result<<endl;
    }

    return 0;
}
