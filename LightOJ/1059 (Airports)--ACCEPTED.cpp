//Problem ID: LightOJ 1059 (Airports)
//Programmer: IQBAL HOSSAIN     Description: MST
//Date: 29-09-17
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
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
typedef pair<int, pii> Node;
typedef vector<int> vi;
typedef vector<pii> vii;
const int  inf = 1<<28;
int numSet, parent[MAX];

vector<Node> V;
vector<int> MST;

bool operator < (const Node a, const Node b)
{
    if(a.first < b.first)
        return true;
    return false;
}

int findSet(int x)
{
    if(parent[x] == x)
        return x;
    return parent[x] = findSet(parent[x]);
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
            numSet--;
            parent[x] = y;
            sum += V[i].first;
            MST.push_back(V[i].first);
        }
    }

    return sum;
}

int main()
{
    int test, caseNo = 1, nodeNo, edgeNo, airportCost;
    int u, v, cost;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d %d", &nodeNo, &edgeNo, &airportCost);
        for(int i = 0; i < edgeNo; i++){
            scanf("%d %d %d", &u, &v, &cost);
            V.push_back(Node(cost, pii(u, v)));
        }

        numSet = nodeNo;        //initialize number of set
        int ans = kruskal();

        int result = (airportCost * numSet) + ans;

        int sum = 0;

        if(airportCost * nodeNo <= result){     //if multiple minimum cost occurs we need take which airports number is maximum
            result = airportCost * nodeNo;
            numSet = nodeNo;
        }
        for(int i = 0, j = nodeNo - 1; i < MST.size(); i++, j--){
            sum += MST[i];
            int temp = (j * airportCost) + sum;
            if(temp <= result){
                if(temp < result){      //firstly we have to consider its total cost, if it is minimum than before we do not need to check airport number
                    result = temp;
                    numSet = j;
                }
                if(temp == result){     //if costs are equal we need to check airport number
                    if(j > numSet){
                        result = temp;
                        numSet = j;
                    }
                }
            }
        }

        printf("Case %d: %d %d\n", caseNo++, result, numSet);

        V.clear();
        MST.clear();
    }

    return 0;
}
