#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#define MAX 800
#define pb push_back
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;

int parent[MAX], nodeNo, mark[MAX][MAX];

struct node
{
    int u, v;
    double w;
};

bool operator<(node A, node B)
{
    return A.w < B.w;
}
vector<node> V;

double calculateDist(int x1, int y1, int x2, int y2)
{
    return (double) sqrt((x1-x2) *(x1-x2) + (y1-y2) *(y1-y2));      //calculate distance
}

int findSet(int x)      //check if they are in same set
{
    if(parent[x] == x)
        return x;
    return parent[x] = findSet(parent[x]);
}

double kruskal()
{
    for(int i = 0; i <= nodeNo; i++)
        parent[i] = i;

    sort(V.begin(), V.end());

    int sz = V.size();
    double ans = 0;

    for(int i = 0; i < sz; i++){
        int x = findSet(V[i].u);
        int y = findSet(V[i].v);
        if(x != y){
            parent[x] = y;
            ans += V[i].w;
        }
    }

    return ans;
}
int main()
{
    int x, y, existingPath;

    while(scanf("%d", &nodeNo) == 1){
        pii coord[MAX];

        for(int i = 0; i < MAX; i++){       //initialize mark
            for(int j = 0; j < MAX; j++)
                mark[i][j] = 0;
        }

        for(int i = 0; i < nodeNo; i++){
            scanf("%d %d", &x, &y);
            coord[i] = make_pair(x, y);
        }

        int x1, y1;
        scanf("%d", &existingPath);

        for(int i = 0; i < existingPath; i++){
            scanf("%d %d", &x1, &y1);
            x1--, y1--;
            mark[x1][y1] = 1, mark[y1][x1] = 1;
            node temp;
            temp.u = x1, temp.v = y1, temp.w = 0;       //initialize weight of exited node as 0
            V.pb(temp);
        }

        for(int i = 0; i < nodeNo; i++){
            for(int j = i + 1; j < nodeNo; j++){
                if(!mark[i][j]){
                    double dist = calculateDist(coord[i].first, coord[i].second, coord[j].first, coord[j].second);
                    node temp;
                    temp.u = i, temp.v = j, temp.w = dist;
                    V.pb(temp);
                }
            }
        }

        double result = kruskal();

        printf("%0.2lf\n", result);
        V.clear();
    }

    return 0;
}
