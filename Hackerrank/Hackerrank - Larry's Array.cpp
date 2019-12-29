//Problem ID: HackerRank - Larry's Array
//Programmer: IQBAL HOSSAIN 	Description: Invariant
//Date: 21/05/19
//Problem Link: https://www.hackerrank.com/challenges/larrys-array/problem
#include <bits/stdc++.h>
#define MAX 1005
using namespace std;

int main()
{
	// #ifndef ONLINE_JUDGE
	// 	freopen("input.txt", "r", stdin);
	// 	freopen("output.txt", "w", stdout);
	// #endif

    int test, n, arr[MAX], pos[MAX];

    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%d", &arr[i]);
            pos[arr[i]] = i;
        }

        for(int i = 1; i <= n; i++){
            if(arr[i] == i)
                continue;
            if(pos[i] < i)
                break;
            while(arr[i] != i){
                if(pos[i] == n){
                    if(pos[i] - 2 < i)
                        break;
                    int p = pos[i];
                    int temp1 = arr[p], temp2 = arr[p-1], temp3 = arr[p-2];
                    arr[p-2] = temp1, arr[p-1] = temp3, arr[p] = temp2;
                    pos[arr[p-2]] = p-2, pos[arr[p-1]] = p - 1, pos[arr[p]] = p;
                }
                else{
                    if((pos[i] - 1) < i)
                        break;
                    int p = pos[i];
                    int temp1 = arr[p-1], temp2 = arr[p], temp3 = arr[p+1];
                    arr[p-1] = temp2, arr[p] = temp3, arr[p+1] = temp1;
                    pos[arr[p-1]] = p-1, pos[arr[p]] = p, pos[arr[p+1]] = p+1;
                }
                if(arr[i] == i)
                	break;
            }
        }
        bool flag = 0;
        for(int i = 1; i <= n; i++){
        	if(arr[i] != i){
        		flag = 1;
        	}
        }
        (flag) ? printf("NO\n") : printf("YES\n");
    }

    return 0;
}