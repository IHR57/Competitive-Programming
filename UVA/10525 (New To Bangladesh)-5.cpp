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

#define MAX 105
#define pb push_back
#define eps 1e-11

typedef long long lint;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

lint dist[MAX][MAX], minTime[MAX][MAX];
int nodeNo, edgeNo;

void init()
{
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            if(i == j){
                dist[i][i] = 0;
            }
            else{
                dist[i][j] = 1LL<<60;
                minTime[i][j] = 1LL<<60;
            }
        }
    }
}
void floydWarshall()
{
    for(int k = 1; k <= nodeNo; k++){
        for(int i = 1; i <= nodeNo; i++){
            for(int j = 1; j <= nodeNo; j++){
                if(minTime[i][j] > minTime[i][k] + minTime[k][j]){
                    minTime[i][j] = minTime[i][k] + minTime[k][j];
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
                else if(minTime[i][j] == minTime[i][k] + minTime[k][j] && dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int main()
{
    int test, u, v, Time, length, query, line = 0;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &nodeNo, &edgeNo);
        init();
        for(int i = 0; i < edgeNo; i++){
            scanf("%d %d %d %d", &u, &v, &Time, &length);
            //we have to reduce time as much as possible
            if(Time < minTime[u][v] || (Time == minTime[u][v] && length < dist[u][v]))
            {
                dist[u][v] = length;
                dist[v][u] = length;
                minTime[u][v] = Time;
                minTime[v][u] = Time;
            }
        }

        floydWarshall();

        scanf("%d", &query);

        while(query--){
            scanf("%d %d", &u, &v);
            if(dist[u][v] == 1LL<<60){
                printf("No Path.\n");
            }
            else
                printf("Distance and time to reach destination is %lld & %lld.\n", dist[u][v], minTime[u][v]);
        }
        if(test)    printf("\n");
    }

    return 0;
}
