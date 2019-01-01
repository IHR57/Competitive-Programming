#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define MAX 100005
using namespace std;

int arr[MAX], tree[3*MAX];

void Insert(int nodeNo, int low, int high)
{
	if(low == high){
		tree[nodeNo] = arr[low];
		return;
	}

	int left = 2 * nodeNo;
	int right = 2 * nodeNo + 1;
	int mid = (low + high) / 2;

	Insert(left, low, mid);
	Insert(right, mid+1, high);

	tree[nodeNo] = tree[left] + tree[right];
}

int query(int nodeNo, int low, int high, int i, int j)
{
	if(i > high || j < low)
		return 0;
	if(low >= i && high <= j){		//if the current node is relevant
		return tree[nodeNo];
	}

	int left = 2 * nodeNo;
	int right = 2 * nodeNo + 1;
	int mid = (low + high) / 2;

	int p1 = query(left, low, mid, i, j);		//recursive call
	int p2 = query(right, mid+1, high, i, j);

	return p1 + p2;			//total sum in the range
}

void updatePlus(int nodeNo, int low, int high, int index, int value)
{
	if(index > high || index < low)
		return;
	if(low == high){		//we have to reach the leaf node to update
		tree[nodeNo] += value;		//add previous cost with new cost
		return;
	}

	int left = 2 * nodeNo;
	int right = 2 * nodeNo + 1;
	int mid = (low + high) / 2;

	updatePlus(left, low, mid, index, value);
	updatePlus(right, mid+1, high, index, value);

	tree[nodeNo] = tree[left] + tree[right];		//updated cost of parent
}

void updateMinus(int nodeNo, int low, int high, int index, int value)
{
	if(index > high || index < low)
		return;
	if(low == high){		//we have to reach the leaf node to update
		tree[nodeNo] -= value;		//add previous cost with new cost
		return;
	}

	int left = 2 * nodeNo;
	int right = 2 * nodeNo + 1;
	int mid = (low + high) / 2;

	updateMinus(left, low, mid, index, value);
	updateMinus(right, mid+1, high, index, value);

	tree[nodeNo] = tree[left] + tree[right];		//updated cost of parent
}

int main()
{
	int test, cases = 1, nodeNumber, queryNumber, range1, range2, command;

	scanf("%d", &test);

	while(test--){
		scanf("%d %d", &nodeNumber, &queryNumber);

		for(int i = 1; i <= nodeNumber; i++){
			scanf("%d", &arr[i]);
		}

        Insert(1, 1, nodeNumber);
		int result;
		printf("Case %d:\n", cases++);

		for(int i = 1; i <= queryNumber; i++){
			scanf("%d", &command);
			if(command == 1){
				scanf("%d", &range1);
				range1++;
				result = query(1, 1, nodeNumber, range1, range1);
				updateMinus(1, 1, nodeNumber, range1, result);
				printf("%d\n", result);
			}
			else if(command == 2){
				scanf("%d %d", &range1, &range2);
				range1++, range2;
				updatePlus(1, 1, nodeNumber, range1, range2);
			}
			else if(command == 3){
				scanf("%d %d", &range1, &range2);
				range1++, range2++;
				result = query(1, 1, nodeNumber, range1, range2);
				printf("%d\n", result);
			}
		}
	}

	return 0;
}
