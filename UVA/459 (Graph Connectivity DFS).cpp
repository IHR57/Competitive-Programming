#include <bits/stdc++.h>
#define MAX 50
using namespace std;

vector<int> graph[MAX];
int visited[MAX];

void dfs(int n)
{
    visited[n] = 1;

    for(int i = 0; i < graph[n].size(); i++){
        if(!visited[graph[n][i]]){
            dfs(graph[n][i]);
        }
    }
}

int main()
{
    int test;
    string s;

    scanf("%d\n\n", &test);

    for(int tc = 1; tc <= test; tc++){
        getline(cin, s);
        int n = s[0] - 'A' + 1;

        memset(visited, 0, sizeof(visited));

        while(1){
            if(!getline(cin, s) || s.empty())
                break;
            int x = s[0] - 'A', y = s[1] - 'A';
            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        int count = 0;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                count++;
                dfs(i);
            }
        }

        if(tc != 1)
            printf("\n");

        printf("%d\n", count);

        for(int i = 0; i < n; i++){
            graph[i].clear();
        }
    }

    return 0;
}
