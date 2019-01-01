#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#define MAX 105
using namespace std;

int Left[2*MAX], Right[2*MAX], visited[2*MAX];
vector<int> graph[2 * MAX];
int n, m;

bool kuhn(int u)        //return true if it is possible to connect
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

    for(int i = 0; i < n; i++){
        memset(visited, 0, sizeof(visited));
        if(kuhn(i)){        //if it is possible to connect
            count++;
        }
    }

    return count;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int factors[MAX], multiples[MAX], test, caseNo = 1;

    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%d", &factors[i]);
        }
        scanf("%d", &m);
        for(int i = 0; i < m; i++){
            scanf("%d", &multiples[i]);
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(multiples[j] % factors[i] == 0){
                    graph[i].push_back(n + j);
                }
            }
        }

        int ans = bipartiteMatching();

        printf("Case %d: %d\n", caseNo++, ans);

        for(int i = 0; i < 2 * MAX; i++){
            graph[i].clear();
        }
    }

    return 0;
}
