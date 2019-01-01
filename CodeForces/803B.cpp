#include <iostream>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <vector>
#include <string.h>
#include <math.h>
#define MAX 200005
using namespace std;

const int INF = 1<<28;

int main()
{
	int dist[MAX], arr[MAX];
	int n, data;

	scanf("%d", &n);

	stack<int> st;

    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
	for(int i = n-1; i >= 0; i--){
		//scanf("%d", &data);
		if(arr[i] == 0){
			st.push(i);
		}
	}

	for(int i = 0; i < MAX; i++)
		dist[i] = INF;

	int temp, temp2;

	for(int i = 0; i < n; i++){
		temp = INF, temp2 = INF;

		temp = st.top();
		st.pop();
		if(!st.empty())
			temp2 = st.top();
		st.push(temp);

		if(abs(temp - i) < dist[i]){
			dist[i] = abs(temp - i);
		}
		if(abs(temp2 - i) < dist[i]){
			dist[i] = abs(temp2 - i);
			st.pop();
		}
	}

	for(int i = 0; i < n; i++){
		printf("%d ", dist[i]);
	}
	printf("\n");

	return 0;
}
