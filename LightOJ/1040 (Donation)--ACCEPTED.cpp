//Problem ID: LightOJ 1040 (Donation)
//Programmer: IQBAL HOSSAIN     Description: MST
//Date: 29-09-17
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cmath>
#define MAX 55
using namespace std;

typedef long long lint;
typedef pair<int, int> pii;
typedef pair<int, pii> Node;

vector<Node> V;

bool operator < (const Node a, const Node b)
{
    if(a.first < b.first)
        return true;
    return false;
}

int parent[MAX];

int findSet(int x)
{
    if(parent[x] == x)
        return x;
    return parent[x] = findSet(parent[x]);
}

bool isSameSet(int x, int y)
{
    return findSet(x) == findSet(y);
}

int kruskal()
{
    int sum = 0;

    for(int i = 0; i < MAX; i++)
        parent[i] = i;

    sort(V.begin(), V.end());

    int sz = V.size();

    for(int i = 0; i < sz; i++){
        int x = findSet(V[i].second.first);
        int y = findSet(V[i].second.second);

        if(x != y){
            parent[x] = y;
        }
        else{
            sum += V[i].first;
        }
    }

    return sum;
}

int main()
{
    int test, caseNo = 1, nodeNo, u;

    scanf("%d", &test);

    while(test--){
        scanf("%d", &nodeNo);

        for(int i = 0; i < nodeNo; i++){
            for(int j = 0; j < nodeNo; j++){
                scanf("%d", &u);
                if(u > 0)
                    V.push_back(Node(u, pii(i, j)));
            }
        }

        int result = kruskal();

        int flag = 1;

        for(int i = 0; i < nodeNo; i++){            //check all the nodes are connected?
            for(int j = 0; j < nodeNo; j++){
                if(!isSameSet(i, j)){
                    flag = 0;
                    break;
                }
                if(!flag)
                    break;
            }
        }

        (flag == 1) ? printf("Case %d: %d\n", caseNo++, result) : printf("Case %d: -1\n", caseNo++);

        V.clear();
    }

    return 0;
}
