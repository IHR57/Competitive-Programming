//Problem ID: LightOJ - 1271 (Better Tour)
//Programmer: IQBAL HOSSAIN     Description: DFS/BFS
//Date: 24/05/19
#include <bits/stdc++.h>
#define MAX 50005
using namespace std;

set<int> s[MAX];
int arr[MAX], parent[MAX], visited[MAX], n;

void bfs(int source)
{
    visited[source] = 1;
    queue<int> q;
    q.push(source);

    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(set<int> :: iterator it = s[u].begin(); it != s[u].end(); it++){
            int v = *it;
            if(!visited[v]){
                visited[v] = 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }
}

void printPath(int v)
{
    if(v == -1)
        return;
    else
        printPath(parent[v]);
    (v == arr[n-1]) ? printf("%d\n", v) : printf("%d ", v);
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int test, caseno = 1;

    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);
        memset(parent, -1, sizeof(parent));
        memset(visited, 0, sizeof(visited));
        for(int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
            if(i){
                s[arr[i-1]].insert(arr[i]);
                s[arr[i]].insert(arr[i-1]);
            }
        }
        bfs(arr[0]);
        printf("Case %d:\n", caseno++);
        printPath(arr[n-1]);
        for(int i = 0; i < MAX; i++)
            s[i].clear();
    }

    return 0;
}