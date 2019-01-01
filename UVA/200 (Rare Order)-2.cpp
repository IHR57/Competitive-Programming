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

#define MAX 10005
#define pb push_back
#define eps 1e-11

typedef long long lint;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int  inf = 1<<28;

vi graph[MAX], ts;

int main()
{
    char temp[MAX];
    char str[MAX][30], ID[MAX];
    int idx = 0, count = 0, inDegree[MAX] = {0};
    map<char, int> myMap;

    while(cin>>temp){
        if(temp[0] == '#')
            break;
        strcpy(str[count], temp);
        int len = strlen(temp);

        for(int i = 0; i < len; i++){
            if(myMap.find(temp[i]) == myMap.end()){
                ID[idx] = temp[i];
                myMap[temp[i]] = idx++;
            }
        }
        count++;
    }

    for(int i = 0; i < count; i++){
        int len = strlen(str[i]);
        int cnt = 0;
        for(int j = i + 1; j < count; j++){
            for(int k = 0; k < len; k++){
                if(str[i][k] != str[j][k] && str[i][k] != '\0' && str[j][k] != '\0' && cnt < 1){
                    int u = myMap[str[i][k]];
                    int v = myMap[str[j][k]];
                    //cout<<u<<" "<<v<<endl;
                    inDegree[v]++;
                    graph[u].pb(v);
                    cnt++;
                }
                if(cnt >= 1)    break;
            }
        }
        }

        queue<int> q;

        for(int i = 0; i < idx; i++){
            if(inDegree[i] == 0)
                q.push(i);
        }

    while(!q.empty()){
        int u = q.front();
        q.pop();
        ts.pb(u);

        for(int i = 0; i < graph[u].size(); i++){
            int v = graph[u][i];
            inDegree[v]--;
            if(inDegree[v] == 0)
                q.push(v);
        }
    }

    for(int i = 0; i < ts.size(); i++){
        printf("%c", ID[ts[i]]);
    }
    printf("\n");

    return 0;
}


