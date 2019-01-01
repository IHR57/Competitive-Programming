#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string.h>
using namespace std;

int queen[30], diagonal1[60], diagonal2[60], column[30], arr[200][15];
int row, col, idx;

void init()
{
	memset(diagonal1, 0, sizeof(diagonal1));
	memset(diagonal2, 0, sizeof(diagonal2));
	memset(column, 0, sizeof(column));
}

void nQueen(int pos, int n)
{
    int flag = 0;
	if(pos == n + 1){		//base case
        for(int i = 1; i <= n; i++){
            arr[idx][i] = queen[i];
        }
        idx++;
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
	int test, n = 0;

	scanf("%d", &test);

	while(test--){
		init();
		idx = 1;
		int count = 1;
		scanf("%d %d", &row, &col);
		if(n)
            printf("\n");
        n = 1;
		nQueen(1, 8);

        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
		for(int i = 1; i < idx; i++){
            if(arr[i][col] == row){
                printf("%2d     ", count++);
                for(int j = 1; j <= 8; j++)
                    printf(" %d", arr[i][j]);
                printf("\n");
            }
		}
	}

	return 0;
}
