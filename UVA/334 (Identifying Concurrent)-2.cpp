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

#define MAX 205
#define pb push_back
#define eps 1e-11

typedef long long lint;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
const double  inf = 1e12;

int graph[MAX][MAX], flag[MAX][MAX];

int main()
{
    int nodeNo, caseNo = 1, eventNo, connect;
    int u, v;
    char strA[100], strB[100] ;

    while(scanf("%d", &nodeNo) == 1){
        if(!nodeNo) break;

        map<string, int> myMap;
        char str[MAX][MAX];
        int idx = 0;

        memset(graph, 0, sizeof(graph));

        for(int i = 0; i < nodeNo; i++){
            scanf("%d", &eventNo);
            scanf("%s", strB);
            if(myMap.find(strB) == myMap.end()){
                myMap[strB] = idx++;
            }

            u = myMap[strB];
            strcpy(str[u], strB);

            for(int j = 1; j < eventNo; j++){
                scanf("%s", strA);
                if(myMap.find(strA) == myMap.end()){
                    myMap[strA] = idx++;
                }

                v = myMap[strA];
                strcpy(str[v], strA);
                //cout<<u<<" "<<v<<endl;
                graph[u][v] = 1;            //directed graph
                u = v;
            }
        }

        scanf("%d", &connect);

        for(int j = 0; j < connect; j++){
            scanf("%s %s", strA, strB);
            u = myMap[strA], v = myMap[strB];
            graph[u][v] = 1;
        }

        for(int k = 0; k < idx; k++){
            for(int i = 0; i < idx; i++){
                for(int j = 0; j < idx; j++){
                    graph[i][j] |= (graph[i][k] & graph[k][j]);     //transitive closure
                }
            }
        }

        int count =  0;

        memset(flag, 0, sizeof(flag));

        for(int i = 0; i < idx; i++){
            for(int j = i + 1; j < idx; j++){
                if(graph[i][j] != 1 && graph[j][i] != 1 && !flag[i][j]){
                    count++;
                    flag[j][i] = 1;
                }
            }
        }

        if(count == 0){
            printf("Case %d, no concurrent events.\n", caseNo++);
        }
        else{
            printf("Case %d, %d concurrent events:\n", caseNo++, count);

            count = 0;
            for(int i = 0; i < idx; i++){
                for(int j = i + 1; j < idx; j++){
                    if(graph[i][j] != 1 && graph[j][i] != 1 && !flag[i][j] && count <= 1){
                        printf("(%s,%s) ", str[i], str[j]);
                        count++;
                    }
                }
            }
            printf("\n");
        }
    }

    return 0;
}

