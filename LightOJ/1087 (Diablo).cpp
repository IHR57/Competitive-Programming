#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 150005
using namespace std;

int arr[MAX], n, tree[4*MAX];

void init(int nodeNo, int low, int high)
{
	if(low == high){
		if(low <= n){       //set 1 in which there is element
			tree[nodeNo] = 1;
		}
		else
			tree[nodeNo] = 0;       //fill other node with 0
		return;
	}

	int left = nodeNo * 2;
	int right = nodeNo * 2 + 1;
	int mid = (low + high) >> 1;

	init(left, low, mid);
	init(right, mid + 1, high);

	tree[nodeNo] = tree[left] + tree[right];
}

void update(int nodeNo, int low, int high, int pos)
{
	if(low == high){
		tree[nodeNo] = 1;
		return;
	}

	int left = nodeNo * 2;
	int right = nodeNo * 2 + 1;
	int mid = (low + high) >> 1;

    if(pos <= mid)
        update(left, low, mid, pos);
    else
        update(right, mid + 1, high, pos);

	tree[nodeNo] = tree[left] + tree[right];
}

int query(int nodeNo, int low, int high, int pos)
{
	int temp;

	if(low == high){
		tree[nodeNo] = 0;
		return arr[low];
	}

	int left = nodeNo * 2;
	int right = nodeNo * 2 + 1;
	int mid = (low + high) >> 1;

	if(pos <= tree[left])
		temp = query(left, low, mid, pos);
	else
		temp = query(right, mid + 1, high, pos - tree[left]);

	tree[nodeNo] = tree[left] + tree[right];
	return temp;
}

int main()
{
	int test, caseNo = 1, q, value, idx, ans;
	char str[50];

	scanf("%d", &test);

	while(test--){
		scanf("%d %d", &n, &q);
		for(int i = 1; i <= n; i++){
			scanf("%d", &arr[i]);
		}

		idx = n;
		init(1, 1, n + q);

		printf("Case %d:\n", caseNo++);

		for(int i = 1; i <= q; i++){
			scanf("%s %d", str, &value);
			if(str[0] == 'c'){
				if(value <= tree[1]){
					ans = query(1, 1, n+q, value);
					printf("%d\n", ans);
				}
				else
					printf("none\n");
			}
			else if(str[0] == 'a'){
                idx = idx + 1;
				update(1, 1, n+q, idx);
				arr[idx] = value;
			}
		}
	}

	return 0;
}
