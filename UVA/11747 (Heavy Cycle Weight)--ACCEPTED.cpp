//Problem ID: UVA 11747 (Heavy Cycle Weight)
//Programmer: IQBAL HOSSAIN     Description: Standard MST
//Date: 27-09-17
#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#define MAX 1005
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> Node;
const int inf = 1<<28;
typedef long long lint;

int parents[MAX];
vector<Node> V;

bool operator < (const Node a, const Node b)
{
	if(a.first < b.first)
		return true;
	return false;
}

int findSet(int x)
{
	if(parents[x] == x)
		return x;
	return parents[x] = findSet(parents[x]);
}

void kruskal()
{
    vector<int> temp;

    int count = 0;

	for(int i = 0; i < MAX; i++)
		parents[i] = i;

	sort(V.begin(), V.end());

	int sz = V.size();

	for(int i = 0; i < sz; i++){
		int x = findSet(V[i].second.first);
		int y = findSet(V[i].second.second);

		if(x != y){
			parents[x] = y;
		}
		else{
            count++;
            temp.push_back(V[i].first);
		}
	}

	if(!count)	printf("forest\n");
    else{
        sz = temp.size();
        for(int i = 0; i < sz - 1; i++){
            printf("%d ", temp[i]);
        }
        printf("%d\n", temp[sz-1]);
    }
}

int main()
{
	int nodeNo, edgeNo, u, v, cost;

	while(scanf("%d %d", &nodeNo, &edgeNo) == 2){
		if(!nodeNo && !edgeNo)
			break;

		for(int i = 0; i < edgeNo; i++){
			scanf("%d %d %d", &u, &v, &cost);
			V.push_back(Node(cost, pii(u, v)));
		}

		kruskal();

		V.clear();
	}

	return 0;
}
