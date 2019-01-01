#include <bits/stdc++.h>
#define MAX 50
using namespace std;

vector<int> graph[MAX], revGraph[MAX];
int visited[MAX],finishing_time, finish[MAX];
int temp, data[MAX];

int dfs(int n)
{
    finishing_time++;
    visited[n] = 1;

    for(int i = 0; i < graph[n].size(); i++){
        if(!visited[graph[n][i]])
            dfs(graph[n][i]);
    }

    finish[n] = ++finishing_time;

    return 0;
}

int dfs2(int n)
{
    data[temp++] = n;
    visited[n] = 1;

    for(int i = 0; i < revGraph[n].size(); i++){
        if(!visited[revGraph[n][i]]){
            dfs2(revGraph[n][i]);
        }
    }

    return 0;
}

int main()
{
    int node, edge, cases = 0, test = 1;

    while(cin>>node>>edge){
        if(!node && !edge)
            break;
        int value = 0;

        if(cases){
            cout<<endl;
            test = 0;
        }

        char str[50][50];
        char str1[50], str2[50];

        map<string, int> myMap;
        for(int i = 0; i < edge; i++){
            cin>>str1>>str2;

            //mapping
            if(myMap.find(str1) == myMap.end()){
                myMap[str1] = value++;
            }
            if(myMap.find(str2) == myMap.end()){
                myMap[str2] = value++;
            }
            int u = myMap[str1], v = myMap[str2];

            strcpy(str[u], str1);
            strcpy(str[v], str2);

            graph[u].push_back(v);
            revGraph[v].push_back(u);
        }

        memset(visited, 0, sizeof(visited));        //make all nodes unvisited
        finishing_time = 0;

        for(int i = 0; i < node; i++){      //run the first dfs
            if(!visited[i])
                dfs(i);
        }

        vector<pair<int, int> > v;

        for(int i = 0; i < node; i++){
            v.push_back(make_pair(finish[i], i));
        }

        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());        //sort in decreasing order

        memset(visited, 0, sizeof(visited));

        cout<<"Calling circles for data set "<<++cases<<":"<<endl;
        for(int i = 0; i < node; i++){
            int m = v[i].second;
            temp = 0;
            if(!visited[m]){
                dfs2(m);
                for(int j = 0; j < temp-1; j++){
                    cout<<str[data[j]]<<", ";
                }
                cout<<str[data[temp-1]]<<endl;
            }
        }

        for(int i = 0; i < node; i++){
            graph[i].clear();
            revGraph[i].clear();
        }
    }

    return 0;
}
