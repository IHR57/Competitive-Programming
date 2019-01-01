#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <sstream>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

#define MAX 1010
#define pb push_back
#define eps 1e-11

typedef long long lint;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int  inf = 1<<28;

map<string, int> myMap;
vi graph[MAX], revGraph[MAX];
int n, m, finishing_time, finish[MAX];
bool visited[MAX];

void dfs1(int source)
{
    finishing_time++;
    visited[source] = 1;

    for(int i = 0; i < graph[source].size(); i++){
        int v = graph[source][i];
        if(!visited[v]){
            dfs1(v);
        }
    }

    finish[source] = ++finishing_time;
}

void dfs2(int source)
{
    visited[source] = 1;

    for(int i = 0; i < revGraph[source].size(); i++){
        int v = revGraph[source][i];
        if(!visited[v]){
            dfs2(v);
        }
    }
}
int main()
{
    string name1, name2;

    while(scanf("%d %d", &n, &m) == 2){
        if(!n && !m)    break;
        myMap.clear();

        scanf(" ");
        for(int i = 1; i <= n; i++){
            getline(cin, name1);
            myMap[name1] = i;       //mapping the name with integer
        }

        for(int i = 1; i <= m; i++){
            getline(cin, name1);
            getline(cin, name2);
            graph[myMap[name1]].pb(myMap[name2]);       //connecting the two node
            revGraph[myMap[name2]].pb(myMap[name1]);
        }

        memset(visited, 0, sizeof(visited));        //make all nodes unvisited
        finishing_time = 0;

        for(int i = 1; i <= n; i++){
            if(!visited[i]){
                dfs1(i);
            }
        }

        vector<pii> vp;

        for(int i = 1; i <=  n; i++){
            vp.pb(make_pair(finish[i], i));
        }

        sort(vp.begin(), vp.end());     //sort according to finishing time
        reverse(vp.begin(), vp.end());      //we have to reverse it, because it was sorted in ascending order

        int numScc = 0;         //number of connected component

        memset(visited, 0, sizeof(visited));        //re-initialize visited

        for(int i = 0; i < n; i++){
            int m = vp[i].second;
            if(!visited[m]){
                numScc++;
                dfs2(m);
            }
        }

        printf("%d\n", numScc);

        for(int i = 0; i < MAX; i++){
            graph[i].clear();
            revGraph[i].clear();
            finish[i] = 0;
        }
    }

    return 0;
}
