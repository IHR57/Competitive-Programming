#include <bits/stdc++.h>
#define MAX 1005
#define INF 2147483647
using namespace std;

int arr[MAX], n, m;

bool isPossible(int x)
{
    int capacity = 0, req = 0;
    for(int i = 0; i < n; i++){
        capacity += arr[i];
        if(capacity > x){
            req++;
            capacity = arr[i];
        }
    }

    if(req + 1 <= m){
        return true;
    }
    return false;
}

int binarySearch(int low, int high)
{
    int mid, ans;
    while(low <= high){
        mid = low + (high - low) / 2;
        if(isPossible(mid)){        //possible to place this
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    return ans;
}

int main()
{
    int test, caseNo = 1;

    scanf("%d",  &test);

    while(test--){
        int Max = -INF, sum = 0;
        scanf("%d %d", &n, &m);
        for(int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
            Max = max(Max, arr[i]);
            sum += arr[i];
        }

        int result = binarySearch(Max, sum);        //low and high

        printf("Case %d: %d\n", caseNo++, result);
    }

    return 0;
}
