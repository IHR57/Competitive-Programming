#include <bits/stdc++.h>
#define MAX 1005
using namespace std;

int Left[MAX], Right[MAX], visited[MAX];
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

int MaxBiparttie()
{
    memset(Left, -1, sizeof(Left));
    memset(Right, -1, sizeof(Right));
    int cnt = 0;
    for(int i = 0; i < n; i++){
        memset(visited, 0, sizeof(visited));
        if(kuhn(i))
            cnt++;
    }

    return cnt;
}

int main()
{

}
