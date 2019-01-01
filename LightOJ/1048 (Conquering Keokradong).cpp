#include <bits/stdc++.h>
#define MAX 1005
#define INF 2147483647
using namespace std;

int arr[MAX], n, k;

bool isPossible(int x)
{
    int sum = 0, required = 0;
    for(int i = 0; i <= n; i++){
        sum += arr[i];
        if(sum > x){
            required++;
            sum = arr[i];
        }
    }

    if(required <= k){
        return true;
    }
    return false;
}

int binarySearch(int low, int high)
{
    int mid, ans;
    while(low <= high){
        mid = (low + high + 1) >> 1;
        if(isPossible(mid)){
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

    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &n,  &k);
        int sum = 0, Max = -INF;
        for(int i = 0; i <= n; i++){
            scanf("%d", &arr[i]);
            sum += arr[i];
            Max = max(Max, arr[i]);
        }

        int ans = binarySearch(Max, sum);

        printf("Case %d: %d\n", caseNo++, ans);

        int temp = n + 1, camp = k + 1;

        sum = 0;
        for(int i = 0; i <= n; i++){
            sum += arr[i];
            if(sum > ans){
                printf("%d\n", sum - arr[i]);
                sum = arr[i];
                camp--;
            }
            else if(sum == ans){
                printf("%d\n", sum);
                sum = 0;
                camp--;
            }
            else if(n - i + 1 == camp){
                printf("%d\n", sum);
                camp--;
                sum = 0;
            }
        }
    }

    return 0;
}
