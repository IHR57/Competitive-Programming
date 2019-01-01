#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
#define MAX 10005
using namespace std;

int main()
{
    int test, m, cases = 1, u, v;
    char str1[50], str2[50];

    scanf("%d", &test);

    while(test--){
        scanf("%d", &m);
        int value = 0;

        map<string, int> myMap;
        int in_degree[MAX] = {0};
        vector<int> graph[MAX];
        vector<int> top_order;

        for(int i = 0; i < m; i++){
            scanf("%s %s", str1, str2);
            if(myMap.find(str1) == myMap.end()){
                myMap[str1] = value++;
            }
            if(myMap.find(str2) == myMap.end()){
                myMap[str2] = value++;
            }
            u = myMap[str1];
            v = myMap[str2];

            //printf("%d %d\n", u, v);
            graph[u].push_back(v);
            in_degree[v]++;
        }

        /*for(int i = 0; i < value; i++){
            printf("indegree of node %d: %d\n", i, in_degree[i]);
        }*/

        queue<int> q;

        for(int i = 0; i < value; i++){
            if(in_degree[i] == 0)
                q.push(i);
        }

        int count = 0;
        while(!q.empty()){
            int x = q.front();
            q.pop();
            top_order.push_back(x);

            for(int i = 0; i < graph[x].size(); i++){
                in_degree[graph[x][i]]--;
                if(in_degree[graph[x][i]] == 0)
                    q.push(graph[x][i]);
            }
            count++;
        }

        if(count == value)
            printf("Case %d: Yes\n", cases++);
        else
            printf("Case %d: No\n", cases++);
    }

    return 0;
}
