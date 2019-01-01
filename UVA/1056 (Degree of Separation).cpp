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
#define eps 1e-11

typedef long long lint;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
const double  inf = 1e12;

int nodeNo, edgeNo;
double dist[MAX][MAX];

void floydWarshall()
{
    for(int k = 0; k < nodeNo; k++){
        for(int i = 0; i < nodeNo; i++){
            for(int j = 0; j < nodeNo; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);      //update distance
            }
        }
    }
}

int main()
{
    char strA[100], strB[100];
    int caseNo = 1;

    while(scanf("%d %d", &nodeNo, &edgeNo) == 2){
        if(!nodeNo && !edgeNo)  break;

        for(int i = 0; i < nodeNo; i++)
            for(int j = 0; j < nodeNo; j++){
                if(i == j)  dist[i][j] = 0;
                else    dist[i][j] = inf;
            }

        map<string, int> myMap;

        int idx = 0;

        for(int i = 0; i < edgeNo; i++){
            scanf("%s %s", strA, strB);
            if(myMap.find(strA) == myMap.end()){
                myMap[strA] = idx++;
            }
            if(myMap.find(strB) == myMap.end()){
                myMap[strB] = idx++;
            }

            int u = myMap[strA];
            int v = myMap[strB];

            dist[u][v] = dist[v][u] = 1;
        }

        floydWarshall();

        int flag = 1, Max = -1;

        for(int i = 0; i < nodeNo; i++){
            for(int j = 0; j < nodeNo; j++){
                if(dist[i][j] == inf){
                    flag = 0; break;
                }
                if(dist[i][j] > Max)
                    Max = dist[i][j];
            }
        }

        if(flag){
            printf("Network %d: %d\n", caseNo++,  Max);
        }
        else
            printf("Network %d: DISCONNECTED\n", caseNo++);
        printf("\n");
    }

    return 0;
}

