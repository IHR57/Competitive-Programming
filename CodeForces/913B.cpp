// BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 1005
using namespace std;

vector<int> graph[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, u, outDegree[MAX] = {0};

    cin>>n;

    for(int i = 2; i <= n; i++){
        cin>>u;
        graph[u].push_back(i);      //directed graph
        outDegree[u]++;
    }

    vector<int> temp;
    for(int i = 1; i <= n; i++){
        if(outDegree[i]){
            temp.push_back(i);
        }
    }

    bool flag = true;

    for(int i = 0; i < temp.size(); i++){
        int u = temp[i];
        int count = 0;
        for(int j = 0; j < graph[u].size(); j++){
            int v = graph[u][j];
            if(graph[v].size() == 0){
                count++;
            }
        }

        if(count < 3){
            flag = false;
            break;
        }
    }

    if(flag)    cout<<"Yes"<<endl;
    else    cout<<"No"<<endl;

    return 0;
}
