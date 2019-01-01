#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#define MAX 55
using namespace std;

struct data
{
    int u, v, w;
};

bool operator<(data A, data B)      //operator overloading
{
    return A.w < B.w;
}

vector<data> vd;
int parent[MAX];

int findSet(int x)          //find the parent
{
    if(parent[x] == x)
        return x;
    return parent[x] = findSet(parent[x]);
}

int MinimumSpanningTree(int n)
{
    for(int i = 0; i <= n; i++)
        parent[i] = i;

    sort(vd.begin(), vd.end());         //sort in ascending order

    int u, v, sz, count = 0, result = 0;

    sz = vd.size();         //number of edge included

    for(int i = 0; i < sz; i++){
        u = findSet(vd[i].u);       //find the representative or parent of u
        v = findSet(vd[i].v);

        if(u != v){     //if they do not belongs to same parent
            parent[u] = v;
            count++;
            result += vd[i].w;

            if(count == n-1)
                break;
        }
    }

    if(count != n-1){       //if it is not possible to build spanning tree
        result = -1;
        return result;
    }
    else
        return result;

}

int main()
{
    int test, cases = 1, u, v, cost, roads;
    char str1[60], str2[60];

    scanf("%d", &test);

    while(test--){
        scanf("%d", &roads);

        map<string, int> myMap;
        int value = 0;

        while(roads--){
            scanf("%s %s %d", str1, str2, &cost);

            //map the string with integer
            if(myMap.find(str1) == myMap.end())
                myMap[str1] = value++;
            if(myMap.find(str2) == myMap.end())
                myMap[str2] = value++;

            u = myMap[str1];
            v = myMap[str2];
            data get;

            get.u = u; get.v = v; get.w = cost;
            vd.push_back(get);
        }

        int result = MinimumSpanningTree(value);        //minimum cost

        printf("Case %d: ", cases++);
        (result == -1) ? printf("Impossible\n") : printf("%d\n", result);

        vd.clear();
    }

    return 0;
}
