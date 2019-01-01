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
const int  inf = 1<<28;

int nodeNo, dist[MAX][MAX], cost[MAX], parents[MAX][MAX];

void floydWarshall()
{
    for(int k = 1; k <= nodeNo; k++){
        for(int i = 1; i <= nodeNo; i++){
            for(int j = 1; j <= nodeNo; j++){
                if(i == k || j == k){
                    if(dist[i][j] > dist[i][k] + dist[k][j]){
                        dist[i][j] = dist[i][k] + dist[k][j];
                        parents[i][j] = parents[k][j];
                    }
                }
                else{
                    if(dist[i][j] > dist[i][k] + dist[k][j] + cost[k]){
                        dist[i][j] = dist[i][k] + dist[k][j] + cost[k];
                        parents[i][j] = parents[k][j];
                    }
                }
            }
        }
    }
}

void printPath(int i, int j)
{
    if(i != j)
        printPath(i, parents[i][j]);
    if(i == j){
        printf("%d", i);
        return;
    }
    printf("-->%d", j);
}

int main()
{
    int test, value;
    char inputStr[100], *tempStr;
    string word;

    getline(cin, word);
    test = atoi(word.c_str());
    getline(cin, word);

    while(test--){
        gets(inputStr);
        tempStr = strtok(inputStr, " ");
        int count = 0;

        while(tempStr != NULL){
            value = atoi(tempStr);
            tempStr = strtok(NULL, " ");
            count++;
            if(value == -1)
                dist[1][count] = inf;
            else
                dist[1][count] = value;
        }

        nodeNo = count;

        for(int i = 2; i <= count; i++){
            int idx = 1;
            gets(inputStr);
            tempStr = strtok(inputStr, " ");

            while(tempStr != NULL){
                value = atoi(tempStr);
                if(value == -1)    dist[i][idx] = inf;
                else dist[i][idx] = value;
                idx++;
                tempStr = strtok(NULL, " ");
            }
        }

        for(int i = 0; i < MAX; i++){
            for(int j = 0; j < MAX; j++)
                parents[i][j] = i;
        }

        for(int i = 1; i <= count; i++)
            scanf("%d", &cost[i]);

        floydWarshall();

        string line;
        int src, dst;

        cin.ignore();

        while(getline(cin, line) && line != ""){
            stringstream ss(line);
            char s[100], t[100];
            ss >> s >> t;
            src = atoi(s);
            dst = atoi(t);
            printf("From %d to %d:\n", src, dst);
            printf("Path: ");
            printPath(src, dst);
            printf("\n");
            printf("Total cost: %d\n\n", dist[src][dst]);
        }
        if(test)
            printf("\n");
    }

    return 0;
}
