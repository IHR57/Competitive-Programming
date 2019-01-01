#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string.h>
#define MAX 2005
using namespace std;

int sequence[MAX];
int L[MAX], M[MAX], n;

void lisIncreasing()		//LIS on increasing order
{
	for(int i = n-1; i >= 0; i--){
        L[i] = 1;
		for(int j = i + 1; j < n; j++){
			if(sequence[j] < sequence[i]){
				L[i] = max(L[j] + 1, L[i]);
			}
		}
	}
}

void lisDecreasing()		//LIS on decreasing order
{
	for(int i = n-1; i >= 0; i--){
        M[i] = 1;
		for(int j = i + 1; j < n; j++){
			if(sequence[j] > sequence[i]){
				M[i] = max(M[j] + 1, M[i]);
			}
		}
	}
}

int main()
{
	int test;

	scanf("%d", &test);
	while(test--){
		scanf("%d", &n);

        for(int i =  0; i < n; i++){
            scanf("%d", &sequence[i]);
        }

		lisIncreasing();
		lisDecreasing();

		int ans = 0;
		for(int i = 0; i < n; i++){
            ans = max(ans, L[i] + M[i] - 1);
		}
		printf("%d\n", ans);
	}

	return 0;
}
