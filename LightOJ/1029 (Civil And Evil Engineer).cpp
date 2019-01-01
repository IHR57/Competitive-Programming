#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 505
using namespace std;

struct data
{
    int u, v, w;
};
bool operator<(data A, data B)
{
    return A.w < B.w;
}

vector<data> vd;
int parent[MAX];

int findSet(int x)          //find the representative of an element
{
    if(parent[x] == x)
        return x;
    return parent[x] = findSet(parent[x]);
}

int MinMaxSpanningTree(int n)
{
    for(int i = 0; i <= n; i++){
        parent[i] = i;              //initialize
    }

    sort(vd.begin(), vd.end());

    int u, v, sz, resultMin = 0, resultMax = 0, count = 0;
    sz = vd.size();

    for(int i = 0; i <sz; i++){
        u = findSet(vd[i].u);
        v = findSet(vd[i].v);
        if(u != v){
            parent[u] = v;
            count++;
            resultMin += vd[i].w;

            if(count == n)
                break;
        }
    }


    //this part calculate cost of maximum spanning tree

    reverse(vd.begin(), vd.end());      //sort in descending order
    count = 0;

    for(int i = 0; i <= n; i++){
        parent[i] = i;              // again initialize parent
    }

    for(int i = 0; i < sz; i++){
        u = findSet(vd[i].u);
        v = findSet(vd[i].v);

        if(u != v){
            parent[u] = v;
            count++;
            resultMax += vd[i].w;

            if(count == n)
                break;
        }
    }

    int finalResult = resultMin + resultMax;

    return finalResult;
}

int main()
{
    int test, cases = 1, a, b, cost, node;

    scanf("%d", &test);

    while(test--){
        scanf("%d", &node);
        while(scanf("%d %d %d", &a, &b, &cost) == 3){
            if(a == 0 && b == 0 && cost == 0)
                break;
            data get;
            get.u = a; get.v = b; get.w = cost;
            vd.push_back(get);
        }

        int result = MinMaxSpanningTree(node);

        printf("Case %d: ", cases++);
        (result % 2 != 0) ? printf("%d/%d\n", result, 2) : printf("%d\n", result/2);

        vd.clear();
    }

    return 0;
}

