//Problem ID: LightOJ - 1425 (The  Monkey and the Oiled Bamboo)
//Programmer: IQBAL HOSSAIN     Description: Greedy
//Date: 26/02/19
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int arr[MAX];

int main()
{
    int n, test, caseno = 1;
    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);
        int Max = -1;
        arr[0] = 0;
        for(int i = 1; i <= n; i++){
            scanf("%d", &arr[i]);
            Max = max(Max, arr[i] - arr[i-1]);
        }

        bool flag = false;
        int k = Max;

        for(int i = 1; i <= n; i++){
            int temp = arr[i] - arr[i-1];
            if(temp > k){
                flag = true;
                break;
            }
            if(temp == k){
                k--;
            }
        }
        (flag) ? printf("Case %d: %d\n", caseno++, Max + 1) : printf("Case %d: %d\n", caseno++, Max);
    }

    return 0;
}
