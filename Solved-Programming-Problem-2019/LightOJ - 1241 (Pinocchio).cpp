//Problem ID: LightOJ - 1241 (Pinocchio)
//Programmer: IQBAL HOSSAIN     Description: Easy
//Date: 14/02/19
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main()
{
	int test, caseno = 1, arr[105], n;

	scanf("%d", &test);

	while(test--){
		scanf("%d", &n);

		arr[0] = 2;			//normal  nose
		for(int i = 1; i <= n ; i++){
			scanf("%d", &arr[i]);
		}

		int ans = 0;
		for(int i = 1; i <= n; i++){
			if(arr[i] > arr[i-1]){
				int d = arr[i] - arr[i-1];
				if(d % 5 == 0){
					ans += (d / 5);
				}
				else{
					ans += (d / 5) + 1;
				}
			}
		}

		printf("Case %d: %d\n", caseno++, ans);
	}

	return 0;
}
