#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string.h>
using namespace std;

int queen[30], diagonal1[60], diagonal2[60], column[30], arr[10][10];
int Max;

void init()
{
	memset(diagonal1, 0, sizeof(diagonal1));
	memset(diagonal2, 0, sizeof(diagonal2));
	memset(column, 0, sizeof(column));
}

void nQueen(int pos, int n)
{
	int sum = 0;
	if(pos == n + 1){		//base case
		for(int i = 1; i <= n; i++){
			sum += arr[i][queen[i]];
		}
		if(sum > Max)
			Max = sum;
		return;
	}

	for(int i = 1; i <= n; i++){
		if(column[i] || diagonal1[i + pos] || diagonal2[n + i - pos])		//if not possible to place the queen
			continue;
		queen[pos] = i;		//queen's position

		column[i] = diagonal1[i+ pos] = diagonal2[n + i - pos] = 1;
		nQueen(pos+1, n);		//recursive call -- backtrack
		column[i] = diagonal1[i+ pos] = diagonal2[n + i - pos] = 0;
	}
}

int main()
{
	int test;

	scanf("%d", &test);

	while(test--){
		for(int i = 1; i <= 8; i++){
			for(int j = 1; j <= 8; j++){
				scanf("%d", &arr[i][j]);
			}
		}

		init();
		Max = 0;		//initialize maximum value
		nQueen(1, 8);

		printf("%5d\n", Max);
	}

	return 0;
}
