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

#define MAX 35
#define pb push_back
#define eps 1e-11

typedef long long lint;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int  inf = 1<<28;

int nodeNo, edgeNo, dist[MAX][MAX];

void floydWarshall()
{
    for(int k = 0; k < nodeNo; k++){
        for(int i = 0; i < nodeNo; i++){
            for(int j = 0; j < nodeNo; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main()
{
    char temp[100];
    int u, v, cost, caseNo = 1;

    while(scanf("%d %d", &nodeNo, &edgeNo) == 2){
        if(!nodeNo && !edgeNo)  break;

        char str[MAX][MAX];

        for(int i = 0; i < MAX; i++){
            for(int j = 0; j < MAX; j++){
                if(i == j)  dist[i][j] = 0;
                else    dist[i][j] = inf;
            }
        }

        for(int i = 0; i < nodeNo; i++){
            scanf("%s", temp);
            strcpy(str[i], temp);
        }

        for(int i = 0; i < edgeNo; i++){
            scanf("%d %d %d", &u, &v, &cost);
            u--, v--;
            dist[u][v] = dist[v][u] = cost;
        }

        floydWarshall();

        int Min = inf, idx;

        for(int i = 0; i < nodeNo; i++){
            int sum = 0;
            for(int j = 0; j < nodeNo; j++){
                sum += dist[i][j];
            }
            if(sum < Min){
                Min = sum;  idx = i;
            }
        }

        printf("Case #%d : %s\n", caseNo++, str[idx]);
    }

    return 0;
}


