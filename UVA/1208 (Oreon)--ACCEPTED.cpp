//Problem ID: UVA 1208 (Oreon)
//Programmer: IQBAL HOSSAIN     Description: MST
//Date: 28-09-17
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#define MAX 105
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> Node;

vector<Node> V;

bool operator < (const Node a, const Node b)
{
	if(a.first < b.first)
		return true;
	return false;
}

int parents[MAX];
char ID[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";     //Cities are labeled alphabetically using the letters in the English alphabet

int findSet(int x)
{
	if(parents[x] == x)
		return x;
	return parents[x] = findSet(parents[x]);
}

void kruskal()
{
	for(int i = 0; i < MAX; i++)
		parents[i] = i;

	sort(V.begin(), V.end());

	int sz = V.size();

	for(int i = 0; i < sz; i++){
		int x = findSet(V[i].second.first);
		int y = findSet(V[i].second.second);

		if(x != y){
			parents[x] = y;
			printf("%c-%c %d\n", ID[V[i].second.first], ID[V[i].second.second], V[i].first);
		}
	}
}

int main()
{
	int test, caseNo = 1, nodeNo, v;

	scanf("%d", &test);

	while(test--){
		scanf("%d", &nodeNo);
		for(int i = 0; i < nodeNo; i++){
			scanf("%d", &v);
			if(v > 0)               //v = 0 means there is no edge
				V.push_back(Node(v, pii(i, 0)));
			for(int j = 1; j < nodeNo; j++){
				scanf(", %d", &v);
				if(v > 0)
					V.push_back(Node(v, pii(i, j)));
			}
		}

		printf("Case %d:\n", caseNo++);

		kruskal();
		V.clear();
	}

	return 0;
}
