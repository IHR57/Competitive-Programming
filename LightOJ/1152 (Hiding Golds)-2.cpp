#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#define MAX 410
using namespace std;

int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};
int Left[MAX], Right[MAX], visited[MAX], row, col, cell[MAX][MAX], value;
vector<int> graph[MAX];

bool kuhn(int u)
{
    for(int i = 0; i < graph[u].size(); i++){
        int v = graph[u][i];
        if(visited[v])
            continue;
        visited[v] = 1;

        if(Right[v] == -1 || kuhn(Right[v])){
            Right[v] = u;
            Left[u] = v;
            return true;
        }
    }

    return false;
}

int bipartiteMatching()
{
    int count = 0;

    memset(Left, -1, sizeof(Left));
    memset(Right, -1, sizeof(Right));

    for(int i = 1; i <= value; i++){
        memset(visited, 0, sizeof(visited));
        if(kuhn(i))
            count++;
    }

    return count;
}
int main()
{
    int test, caseNo = 1;

    scanf("%d", &test);

    while(test--){
        char str[50][50];
        scanf("%d %d", &row, &col);
        for(int i = 1; i <= row; i++){
            scanf("%s", str[i] + 1);
        }

        memset(cell, 0, sizeof(cell));

        value = 0;

        for(int i = 1; i <= row; i++){
            for(int j = 1; j <= col; j++){
                if(str[i][j] == '*'){
                    cell[i][j] = ++value;
                }
            }
        }

        for(int i = 1; i <= row; i++){
            for(int j = 1; j <= col; j++){
                if(cell[i][j]){
                    for(int k = 0; k < 4; k++){
                        int tx = i + fx[k];
                        int ty = j + fy[k];
                        if(tx >= 1 && tx <= row && ty >= 1 && ty <= col && cell[tx][ty]){
                            graph[cell[i][j]].push_back(cell[tx][ty]);
                        }
                    }
                }
            }
        }

        int ans = bipartiteMatching();

        printf("%d\n", value - ans + ans / 2);

        for(int i = 0; i < MAX; i++)
            graph[i].clear();
    }

    return 0;
}
