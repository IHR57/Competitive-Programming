#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 1000005
using namespace std;

typedef long long lint;

struct node
{
	lint sum, prop;
} tree[4*MAX];

void init(lint nodeNo, lint low, lint high)
{
	if(low == high){
		tree[nodeNo].sum = 0;		//initially all values are zero
		tree[nodeNo].prop = 0;
		return;
	}

	lint left = nodeNo * 2;
	lint right = nodeNo * 2 + 1;
	lint mid = (low + high) >> 1;

	init(left, low, mid);
	init(right, mid + 1, high);

	tree[nodeNo].sum = tree[left].sum + tree[right].sum;
	tree[nodeNo].prop = 0;
}

void update(lint nodeNo, lint low, lint high, lint i, lint j, lint val)		//add val between the range i and j
{
	if(i > high || j < low)
		return;
	if(low >= i && high <= j){
		tree[nodeNo].sum += ((high - low + 1) * val);		//lazy propagation
		tree[nodeNo].prop += val;
		return;
	}

	lint left = nodeNo * 2;
	lint right = nodeNo * 2 + 1;
	lint mid = (low + high) >> 1;

	update(left, low, mid, i, j, val);
	update(right, mid + 1, high, i, j, val);

	tree[nodeNo].sum = tree[left].sum + tree[right].sum + (high - low + 1) * tree[nodeNo].prop;
}

lint query(lint nodeNo, lint low, lint high, lint i, lint j, lint carry)
{
	if(i > high || j < low)
		return 0;
	if(low >= i && high <= j){
		return (lint)tree[nodeNo].sum + carry * (high - low + 1);
	}

	lint left = nodeNo * 2;
	lint right = nodeNo * 2 + 1;
	lint mid = (low + high) >> 1;

	lint p1 = query(left, low, mid, i, j, carry + tree[nodeNo].prop);
	lint p2 = query(right, mid + 1, high, i, j, carry + tree[nodeNo].prop);

	return p1 + p2;
}

int main()
{
	lint test, n, q, x, y, value, cmnd;

	scanf("%lld", &test);

	while(test--){
		scanf("%lld %lld", &n, &q);

		init(1, 1, n);		//initialize segment tree

		for(int i = 0; i < q; i++){
			scanf("%lld", &cmnd);		//command
			if(cmnd == 0){
				scanf("%lld %lld %lld", &x, &y, &value);		//add value between range x and y
				update(1, 1, n, x, y, value);
			}
			else if(cmnd == 1){
				scanf("%lld %lld", &x, &y);
				lint ans = query(1, 1, n, x, y, 0);
				printf("%lld\n", ans);
			}
		}
	}

	return 0;
}
