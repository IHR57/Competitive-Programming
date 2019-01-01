//Problem ID: UVA 11228 (Transportation System)
//Programmer: IQBAL HOSSAIN     Description: MST
//Date: 28-09-17
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#define MAX 1005
using namespace std;

typedef long long lint;
typedef pair<int, int> pii;
typedef pair<double, pii> Node;
vector<Node> V;

bool operator < (const Node a, const Node b)
{
	if(a.first < b.first)
		return true;
	return false;
}

int parents[MAX];
double maxDist, longSum, shortSum;

double calculate(int x1, int y1, int x2, int y2)
{
	return (double)sqrt((x1 - x2) * (x1 - x2) + (y1 - y2 ) * (y1 - y2));
}

int findSet(int x)
{
	if(parents[x] == x)
		return x;
	return parents[x] = findSet(parents[x]);
}

int kruskal()
{
	for(int i = 0; i < MAX; i++)
		parents[i] = i;

	sort(V.begin(), V.end());

	int sz = V.size(), state = 1;

	for(int i = 0; i < sz; i++){
		int x = findSet(V[i].second.first);
		int y = findSet(V[i].second.second);

		if(x != y){
			parents[x] = y;
			if(V[i].first <= maxDist){
				shortSum += V[i].first;
			}
			else{
				longSum += V[i].first;
				state++;
			}
		}
	}

	return state;
}

int main()
{
	int test, caseNo = 1, x, y, cost, nodeNo;

	scanf("%d", &test);

	while(test--){
		scanf("%d %lf", &nodeNo, &maxDist);

		pair<int, int> coord[MAX];

		for(int i = 0; i < nodeNo; i++){
			scanf("%d %d", &x, &y);
			coord[i] = make_pair(x, y);
		}

		for(int i = 0; i < nodeNo; i++){
			for(int j = i + 1; j < nodeNo; j++){
				int u = i;
				int v = j;
				double dist = calculate(coord[i].first, coord[i].second, coord[j].first, coord[j].second);
				V.push_back(Node(dist, pii(u, v)));
			}
		}

		longSum = 0, shortSum = 0;

		int state = kruskal();

		printf("Case #%d: %d %.lf %.lf\n", caseNo++, state, shortSum, longSum);

		V.clear();
	}

	return 0;
}
