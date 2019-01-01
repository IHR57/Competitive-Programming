#include <bits/stdc++.h>
#define MAX 8005
using namespace std;

vector<int> graph[2*MAX], revGraph[2*MAX];          //if there are n variables we need 2*n nodes for 2-sat problem
int finishing_time[2*MAX], scc_no[2*MAX], tym = 0;
bool used[2*MAX];

int dfs1(int n)         //this function calculate finishing time
{
    tym++;
    used[n] = true;

    for(int i = 0; i < graph[n].size(); i++){
        if(!used[graph[n][i]])
            dfs1(graph[n][i]);
    }

    finishing_time[n] = ++tym;
}

int dfs2(int n, int no)         //calculate strongly connected component and finishing_time of reversed graph
{
    scc_no[n] = no;
    used[n] = true;
    tym++;

    for(int i = 0; i < revGraph[n].size(); i++){
        if(!used[revGraph[n][i]]){
            dfs2(revGraph[n][i], no);
        }
    }

    finishing_time[n] = ++tym;
}

int main()
{
    int test, n, m, u, v, cases = 1;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &m, &n);     //m - number of condition ; n - number of variables

        while(m--){
            scanf("%d %d", &u, &v);

            if(u > 0 && v > 0){
                    //if both u and v are positive
                graph[n+u].push_back(v);
                graph[n+v].push_back(u);
                revGraph[v].push_back(n+u);
                revGraph[u].push_back(n+v);
            }
            else if(u > 0 && v < 0){
                v = abs(v);                            //if u positive and v negative
                graph[n+u].push_back(n+v);
                graph[v].push_back(u);
                revGraph[n+v].push_back(n+u);
                revGraph[u].push_back(v);
            }
            else if(u < 0 && v > 0){                   //if u negative v positive
                u = abs(u);
                graph[u].push_back(v);
                graph[n+v].push_back(n+u);
                revGraph[v].push_back(u);
                revGraph[n+u].push_back(n+v);
            }
            else{                           //if both u and v negative
                u = abs(u);
                v = abs(v);
                graph[u].push_back(n+v);
                graph[v].push_back(n+u);
                revGraph[n+v].push_back(u);
                revGraph[n+u].push_back(v);
            }

        }

        tym = 0;
        for(int i = 1; i <= 2 * n; i++)         //make all node unvisited
            used[i] = false;

        for(int i = 1; i <= 2 * n; i++){
            if(!used[i])
                dfs1(i);
        }

       // for(int i = 1; i <= 2 * n; i++){
         //   printf("%d = %d\n", i, finishing_time[i]);
        //}

        vector<pair<int, int> > vp;

        for(int i = 1; i <= 2 * n; i++){
            vp.push_back(make_pair(finishing_time[i], i));
        }

        sort(vp.begin(), vp.end());     //this will sort ascending order but we need descending
        reverse(vp.begin(), vp.end());          //this will sort in descending order

        for(int i = 1; i <= 2 * n; i++)     //again make all node unvisited
            used[i] = false;
        tym = 0;

        for(int i = 0, k = 0; i < 2 * n; i++){
            int j = vp[i].second;
            if(!used[j]){
                k++;
                dfs2(j, k);         //dfs call on reverse graph
            }
        }
        //for(int i = 1; i <= 2 * n; i++){
          //  printf("%d = %d\n", i, finishing_time[i]);
        //}

        bool satisfiable = true;

        for(int i = 1; i <= 2 * n; i++)
            used[i] = false;

        for(int i = 1; i <= n; i++){
            if(scc_no[i] == scc_no[i+n]){
                satisfiable = false;
            }

            if(finishing_time[i] > finishing_time[i+n]){
                used[i] = true;
                used[i+n] = false;
            }
            else{
                used[i] = false;
                used[i+n] = true;
            }
        }

        if(satisfiable){
            printf("Case %d: Yes\n", cases++);
            int count = 0;
            for(int i = 1; i <= n; i++){
                if(used[i]){
                    count++;
                }
            }
            printf("%d", count);

            for(int i = 1; i <= n; i++){
                if(used[i])
                    printf(" %d", i);
            }
            printf("\n");
        }

        else{
            printf("Case %d: No\n", cases++);
        }

        for(int i = 0; i <= 2 * n; i++){
            graph[i].clear();
            revGraph[i].clear();
        }

    }
    return 0;
}
