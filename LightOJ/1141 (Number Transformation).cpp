#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
#define pb push_back
#define MAX 1100
using namespace std;

typedef long long lint;
vector<int> primeFactor[MAX];
vector<int> graph[MAX];
int dist[MAX], visited[MAX];
const int inf = 1<<28;

/*void connectGraph(int n, int destination)        //construct a graph
{
    if(n > destination)        //base case for recursion
        return;
    }
    for(int i = 0; i < primeFactor[n].size(); i++){
        n += primeFactor[n][i];
        if(!traverse[n]){
            cout<<n<<endl;
            graph[n-primeFactor[n][i]].push_back(n);
            graph[n].push_back(n-primeFactor[n][i]);
            traverse[n] = 1;
            connectGraph(n, destination);
        }
        //connectGraph(n, destination);            //recursive call
    }
}*/

int breadthFirst(int source, int destination)
{
    for(int i = 0; i < MAX; i++){
        dist[i] = inf;
    }
    memset(visited, 0, sizeof(visited));

    queue<int> q;
    visited[source] = 1;
    dist[source] = 0;
    q.push(source);

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int i = 0; i < primeFactor[u].size(); i++){
            int temp = u + primeFactor[u][i];
            if(!visited[temp] && temp <= destination){
                q.push(temp);
                visited[temp] = 1;
                dist[temp] = dist[u] + 1;
            }
        }
    }

    return dist[destination];
}

void genPrimeFactor()           //pre generate all prime factor of number in the range 1 to 1000
{
    for(int i = 4; i < MAX; i++){
        int temp = i;
        for(int j = 2; j <= i/2; j++){
            if(temp % j == 0){
                while(temp % j == 0){
                    temp /= j;
                }
                primeFactor[i].push_back(j);
            }
        }
    }
}

int main()
{
    genPrimeFactor();       //generating prime factor

    int test, caseNo = 1;
    int source, destination;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &source, &destination);
        //connectGraph(source, destination);
        int result = breadthFirst(source, destination);

        if(result == inf)
            printf("Case %d: -1\n", caseNo++);
        else
            printf("Case %d: %d\n", caseNo++, result);

        for(int i = 0; i < MAX; i++)
            graph[i].clear();
    }

    return 0;
}
