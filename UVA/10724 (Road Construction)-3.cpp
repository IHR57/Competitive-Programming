#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <sstream>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <iterator>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;

#define MAX 55
#define pb push_back
#define eps 1e-10

typedef long long lint;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
const double  inf = 1e12;

pii coord[MAX];
int nodeNo, edgeNo, graph[MAX][MAX];
double dist[MAX][MAX];

double calculateDistance(int x1, int y1, int x2, int y2)        //distance between two node
{
    return (double)sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}


void floydWarshall()
{
    for(int k = 1; k <= nodeNo; k++){
        for(int i = 1; i <= nodeNo; i++){
            for(int j = 1; j <= nodeNo; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);      //update distance
            }
        }
    }
}


int main()
{
    int x, y, u, v;

    while(scanf("%d %d", &nodeNo, &edgeNo) == 2){
        if(!nodeNo && !edgeNo)  break;

        //initialize graph
        for(int i = 1; i <= nodeNo; i++){
            for(int j = 1; j <= nodeNo; j++){
                if(i == j)  dist[i][j] = 0;
                else    dist[i][j] = inf;
            }
        }

        for(int i = 1; i <= nodeNo; i++){
            scanf("%d %d", &x, &y);
            coord[i] = pii(x, y);           //coordinate of i'th node
        }

        memset(graph, 0, sizeof(graph));

        for(int i = 1; i <= edgeNo; i++){
            scanf("%d %d", &u, &v);
            double d = calculateDistance(coord[u].first, coord[u].second, coord[v].first, coord[v].second);
            //cout<<d<<endl;
            dist[u][v] = d;
            dist[v][u] = d;
            graph[u][v] = 1;
            graph[v][u] = 1;
        }

       floydWarshall();

        double Min = 0;
        int idx1, idx2;

        for(int i = 1; i <= nodeNo; i++){
            for(int j = i + 1; j <= nodeNo; j++){
                if(graph[i][j] != 1){
                    //cout<<i<<" "<<j<<endl;
                    double ans = 0;
                    double d = calculateDistance(coord[i].first, coord[i].second, coord[j].first, coord[j].second);
                    for(int p = 1; p <= nodeNo; p++){
                        for(int q = p + 1; q <= nodeNo; q++){
                            ans += dist[p][q] - min(dist[p][q], min(dist[p][i] + dist[j][q] + d, dist[p][j] + dist[i][q] + d));
                            if(ans > 0 && ans > Min + eps)
                                Min = ans, idx1 = i, idx2 = j;
                        }
                    }
                }
            }
        }
        if(Min > 1e-8)
            printf("%d %d\n", idx1, idx2);
        else
            printf("No road required\n");
    }

    return 0;
}

