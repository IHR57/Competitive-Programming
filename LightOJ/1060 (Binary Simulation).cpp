#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>
#define MAX 100005
using namespace std;

int arr[MAX], toggle[3*MAX];

void update(int nodeNo, int low, int high, int i, int j)
{
	if(i > high || j < low)
		return;
	if(low >= i && high <= j){
		toggle[nodeNo] ^= 1;        //if on makes it off vice versa
		return;
	}

	int mid = (low + high)>>1;

	update(nodeNo*2, low, mid, i, j);
	update(nodeNo*2+1, mid+1, high, i, j);
}

int query(int nodeNo, int low, int high, int position)
{
	if(position < low || position > high)
		return 0;
	if(low >= position && high <= position)
		return toggle[nodeNo];

	int mid = (low + high)>>1;
	if(position <= mid)
		return query(nodeNo*2, low, mid, position) ^ toggle[nodeNo];
	else
		return query(nodeNo*2+1, mid+1, high, position) ^ toggle[nodeNo];
}

int main()
{
	int test, cases = 1, queryNumber, r1, r2;
	char str[100005], ch[10];

	scanf("%d", &test);

	while(test--){
		scanf("%s", str);
		int len = strlen(str);

		memset(toggle, 0, sizeof(toggle));

		for(int i = 1; i <= len; i++){
			arr[i] = str[i-1] - 48;		//converting character to integer
		}

		scanf("%d", &queryNumber);			//number of query

		printf("Case %d:\n", cases++);

		while(queryNumber--){
			scanf("%s", ch);

			if(ch[0] == 'I'){
				scanf("%d %d", &r1, &r2);
				update(1, 1, len, r1, r2);
			}

			else if(ch[0] == 'Q'){
				scanf("%d", &r1);       //output  the light is on or off
				int result = query(1, 1, len, r1);
				printf("%d\n", result ^ arr[r1]);
			}
		}
	}

	return 0;
}

