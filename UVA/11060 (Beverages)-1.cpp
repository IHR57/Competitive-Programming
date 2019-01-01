#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
#include <map>
#define MAX 105
using namespace std;

int main()
{
    int node, edge, value, cases = 1;
    char str1[100];
    char id[105][105];

    while(cin>>node){
        vector<int> graph[MAX];
        map<string, int> myMap;
        vector<int> topsort_order;
        int in_degree[MAX] = {0};
        //top sort_order.clear();
        value = 0;
        for(int i = 0; i < node; i++){
            cin>>str1;
            strcpy(id[i], str1);
            if(myMap.find(str1) == myMap.end()){        //mapping the string with integer
                myMap[str1] = value++;
            }
        }

        for(int i = 0; i < node; i++){
            in_degree[i] = 0;
        }
        cin>>edge;

        for(int i = 0; i < edge; i++){
            cin>>str1;
            int u = myMap[str1];
            cin>>str1;
            int v = myMap[str1];
            //cout<<u<<" "<<v<<endl;
            graph[u].push_back(v);      //this is directed graph
            in_degree[v]++;
        }
        priority_queue<int, vector<int>, greater<int> > q;       //declaring priority queue

        for(int i = 0; i < node; i++){
            if(in_degree[i] == 0)
                q.push(i);
        }

        while(!q.empty()){
            int u = q.top();
            q.pop();
            topsort_order.push_back(u);

            for(int i = 0; i < graph[u].size(); i++){
                in_degree[graph[u][i]]--;           //decrement the dependency
                if(in_degree[graph[u][i]] == 0)
                    q.push(graph[u][i]);        //if in_degree becomes zero then push it
            }
        }

        cout<<"Case #"<<cases++<<": "<<"Dilbert should drink beverages in this order:";
        for(int i = 0; i < topsort_order.size(); i++){
            cout<<" "<<id[topsort_order[i]];
        }
        cout<<"."<<endl<<endl;

        topsort_order.clear();
    }

    return 0;

}
