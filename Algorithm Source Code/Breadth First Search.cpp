#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

vector<int> matrix[100];
char color[100];

void BreadthFirst(int source)
{
    for(int i = 0; i < 100; i++){
        color[i] = 'w';
    }

    queue<int> q;

    q.push(source);
    color[source] = 'g';

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int i = 0; i < matrix[u].size(); i++){
            if(color[matrix[u][i]] == 'w'){
                color[matrix[u][i]] = 'g';
                q.push(matrix[u][i]);
            }
        }
        cout<<u<<"->";

        color[u] = 'b';
    }
    cout<<endl;
}

int main()
{
    int node, edge, a, b, source;

    cout<<"Enter number of node and edge: ";
    cin>>node>>edge;

    for(int i= 0; i < edge; i++){
        cin>>a>>b;
        matrix[a].push_back(b);     //bidirectional graph
        matrix[b].push_back(a);
    }

    cout<<"Enter the source vertex for start traversing: ";
    cin>>source;

    BreadthFirst(source);

    return 0;
}
