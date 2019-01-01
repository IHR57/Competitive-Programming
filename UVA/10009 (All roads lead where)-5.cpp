//Problem ID: UVA 10009 (All Roads Lead Where?)
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <string>
#define MAX 100
using namespace std;

char graph[MAX][MAX], color[MAX];
string id[MAX], first, second;
int pre[MAX], nodeCounter;

void init()     //initialization
{
    for(int i = 0; i < MAX; i++){
        for(int j =  0; j < MAX; j++){
            graph[i][j] = '0';
        }
    }
}

int getID(string one)
{
    for(int i = 0; i < nodeCounter; i++){
        if(id[i] == one){           //if node is exists
            return i;
        }
    }
    id[nodeCounter] = one;
    return nodeCounter++;
}

void printPath(int t, int s)        //print path from source to destination
{
    if(t == s){
        cout<<id[s][0];
        return;
    }
    printPath(pre[t], s);
    cout<<id[t][0];
}

void breadthFirstSearch(int source, int destination)
{
    for(int i = 0; i < MAX; i++){
       // pre[i] = INF;
        color[i] = 'w';
    }

    pre[source] = source;
    color[source] = 'g';
    queue<int> q;

    q.push(source);

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int i = 0; i < nodeCounter; i++){
            if(graph[u][i] == '1' && color[i] == 'w'){
                color[i] = 'g';
                pre[i] = u;
                q.push(i);
            }
        }
        color[u] = 'b';
    }

    printPath(destination, source);
    //cout<<endl;
}

int main()
{
    int test, edges, query, a, b;

    cin>>test;

    while(test--){
        cin>>edges>>query;
        nodeCounter = 0;
        init();         //initialization

        for(int i = 0; i < edges; i++){
            cin>>first>>second;
            a = getID(first);       //convert string to a fixed id number
            b = getID(second);
            graph[a][b] = '1';
            graph[b][a] = '1';      //this is bidirectional graph
        }

        for(int i = 0; i < query; i++){
            cin>>first>>second;
            a = getID(first);
            b = getID(second);

            breadthFirstSearch(a, b);
            cout<<endl;
        }
        if(test)
            cout<<endl;
    }

    return 0;
}
