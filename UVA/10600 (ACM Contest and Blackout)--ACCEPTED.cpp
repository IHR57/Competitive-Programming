//Problem ID: UVA 10600 (ACM Contest and Blackout)
//Programmer: IQBAL HOSSAIN     Description: MST + second Best MST
//Date: 27-09-17
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

#define MAX 105
#define pb push_back
#define eps 1e-11

typedef long long lint;
typedef pair<int, int> pii;
typedef pair<int, pii> Node;
typedef vector<int> vi;
typedef vector<pii> vii;
const int  INF = 1<<28;

vector<Node> V;
int m, parents[MAX];

bool operator < (const Node a, const Node b)
{
	if(a.first < b.first)			//sorting in ascending order
		return true;
	return false;
}

void init(int n)
{
	m = n;
	for(int i = 0; i < MAX; i++)
		parents[i] = i;
}

int findSet(int x)		//find the set or node in which it belongs
{
	if(parents[x] == x)
		return x;
	return parents[x] = findSet(parents[x]);		//path compression
}

bool isSameSet(int x, int y)		//check if two node are in same set
{
	return findSet(x) == findSet(y);
}

void unionSet(int i, int j)			//unite two set if they are not in same set
{
	int x = findSet(i);
	int y = findSet(j);

	if(!isSameSet(x, y)){
		parents[x] = y;
		m--;
	}
}

vector <Node> kruskal(int v)
{
	vector<Node> MST;
	init(v);
	sort(V.begin(), V.end());

	int sz = V.size();

	for(int i = 0; i < sz; i++){
		int cost = V[i].first;
		int src = V[i].second.first;
		int dst = V[i].second.second;
		if(!isSameSet(src, dst)){
			MST.pb(Node(cost, pii(src, dst)));
			unionSet(src, dst);
		}
	}

	return MST;			//return vector MST ; which contains edges that are used to build Minimum spanning tree
}

int secondBestMST(int k, int source, int destination)
{
	int total = 0;
	init(k);

	for(int i = 0; i < V.size(); i++){
		int src = V[i].second.first;
		int dst = V[i].second.second;
		if(src == source && dst == destination)		//if the path which are in MST
			continue;
		if(!isSameSet(src, dst)){
			unionSet(src, dst);
			total += V[i].first;
		}
	}

	if(m != 1)
		return INF;

	return total;
}

int main()
{
    int test, nodeNo, edgeNo, result1, result2;
    int a, b, cost;
    vector<Node> MST;

    scanf("%d", &test);

    while(test--){
    	scanf("%d %d", &nodeNo, &edgeNo);

    	for(int i = 0; i < edgeNo; i++){
    		scanf("%d %d %d", &a, &b, &cost);
    		V.pb(Node(cost, pii(a, b)));
    	}

    	MST = kruskal(nodeNo);
    	result1 = 0, result2 = INF;

    	for(int i = 0; i < MST.size(); i++){
    		result2 = min(result2, secondBestMST(nodeNo, MST[i].second.first, MST[i].second.second));
    		result1 += MST[i].first;
    	}

    	if(result2 == INF)
    		printf("%d %d\n", result1, result1);
    	else{
    		printf("%d %d\n", result1, result2);
    	}
    	V.clear();
    }

    return 0;
}
