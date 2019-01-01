#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <cstring>
#define MAX 10005
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

vector<int> graph[MAX];
set<int> s;
set<pii> st;

int main()
{
    int island, boat_service, c[MAX], u, v, candy;

    while(scanf("%d %d", &island, &boat_service) == 2){
        queue<pii> q;
        for(int i = 0; i < island; i++){
            scanf("%d", &c[i]);
            pii temp(i, c[i]);
            q.push(temp);
            st.insert(temp);
            s.insert(c[i]);
        }
        for(int i = 0; i < boat_service; i++){
            scanf("%d %d", &u, &v);
            u--, v--;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        while(!q.empty()){
            pii f = q.front();
            q.pop();
            u = f.first, candy = f.second;
            for(int i = 0; i < graph[u].size(); i++){
                v = graph[u][i];
                int t = __gcd(candy, c[v]);
                pii temp(v, t);
                if(!st.count(temp)){        //if it is new state
                    st.insert(temp);
                    s.insert(t);
                    q.push(temp);
                }
            }
        }

        printf("%d\n", s.size());
        s.clear();
        st.clear();
        for(int i = 0; i < MAX; i++)
            graph[i].clear();
    }

    return 0;
}
