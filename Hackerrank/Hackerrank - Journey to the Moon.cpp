//Problem ID: HackerRank - Journey to the Moon
//Programmer: IQBAL HOSSAIN     Description: Graph/DFS
//Date: 23/05/19
//Problem Link: https://www.hackerrank.com/challenges/journey-to-the-moon/problem
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

vector<int> graph[MAX];
int visited[MAX], cnt;

void dfs(int u)
{
    visited[u] = 1;
    cnt++;
    for(int i = 0; i < graph[u].size(); i++){
        int v = graph[u][i];
        if(!visited[v]){
            dfs(v);
        }
    }
}

int main()
{
    int n, m, u, v;
    scanf("%d %d", &n, &m);

    for(int i = 0; i < m; i++){
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> arr;
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            cnt = 0;
            dfs(i);
            arr.push_back(cnt);
        }
    }
    int sum = 0;
    for(int i = 0; i < arr.size(); i++){
        sum += arr[i];
    }

    long long ans = 0;
    for(int i = 0; i < arr.size() - 1; i++){
        sum -= arr[i];
        ans += (1LL * arr[i] * sum);
    }

    printf("%lld\n", ans);

    return 0;
}