#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#define MAX 105
using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, int> data;
int n, m;
vector<int> graph[MAX];
int Left[MAX], Right[MAX], visited[MAX];

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

    for(int i = 0; i < n; i++){
        memset(visited, 0, sizeof(visited));
        if(kuhn(i))
            count++;
    }

    return count;
}
int main()
{
    int test, caseNo = 1, height, age, isDivorced;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &n, &m);     //number of element in men and women
        vector<data> V;
        for(int i = 0; i < n; i++){
            scanf("%d %d %d", &height, &age, &isDivorced);
            V.push_back(make_pair(make_pair(height, age), isDivorced));
        }

        for(int i = 0; i < m; i++){
            scanf("%d %d %d", &height, &age, &isDivorced);
            V.push_back(make_pair(make_pair(height, age), isDivorced));
        }

        int sz = V.size();
        for(int i = 0; i < n; i++){
            for(int j = n; j < sz; j++){
                if(abs(V[i].first.first - V[j].first.first) <= 12 && abs(V[i].first.second - V[j].first.second) <= 5 && V[i].second == V[j].second){
                    graph[i].push_back(j);
                }
            }
        }

        int ans = bipartiteMatching();      //finding maximum matching

        printf("Case %d: %d\n", caseNo++, ans);

        for(int i = 0; i < MAX; i++)
            graph[i].clear();
        V.clear();
    }

    return 0;
}
