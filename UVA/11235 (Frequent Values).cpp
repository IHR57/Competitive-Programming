#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cstdio>
#define MAX 200005
using namespace std;

int arr[MAX], Start[MAX], counter[MAX];
int tree[4 * MAX];

void init(int nodeNo, int low, int high)
{
    if(low == high){
        tree[nodeNo] = counter[arr[low]];
        return;
    }

    int left = nodeNo * 2;
    int right = nodeNo * 2 + 1;
    int mid = (low + high) / 2;

    init(left, low, mid);
    init(right, mid + 1, high);

    if(tree[left] >= tree[right])
        tree[nodeNo] = tree[left];
    else
        tree[nodeNo] = tree[right];
}

int query(int nodeNo, int low, int high, int i, int j)
{
    int ans;

    if(i > high || j < low)
        return -1;
    if(low >= i && high <= j){
        return tree[nodeNo];
    }

    int left = nodeNo * 2;
    int right = nodeNo * 2 + 1;
    int mid = (low + high) / 2;

    int p1 = query(left, low, mid, i, j);
    int p2 = query(right, mid + 1, high, i, j);

    if(p1 == -1)
        ans = p1;
    if(p2 == -1)
        ans = p2;
    if(p1 >= p2)
        ans = p1;
    else
        ans = p2;

    return ans;
}

int main()
{
    int n, q, x, y;

    while(scanf("%d", &n) == 1){
        if(!n)  break;
        scanf("%d", &q);

        memset(counter, 0, sizeof(counter));
        memset(Start, -1, sizeof(Start));

        for(int i = 1; i <= n; i++){
            scanf("%d", &arr[i]);
            arr[i] = arr[i] + 100000;
            counter[arr[i]]++;
            if(counter[arr[i]] == 1)
                Start[arr[i]] = i;      //start index of a particular number
        }

        init(1, 1, n);

        for(int i = 1; i <= q; i++){
            scanf("%d %d", &x, &y);
            if(arr[x] == arr[y]){       //if they are same all the values between them must be same
                printf("%d\n", y - x + 1);
                continue;
            }

            int count1 = counter[arr[x]] - x + Start[arr[x]];       //number of element in the range i, k
            int count2 = y - Start[arr[y]] + 1;         //number of j type element
            int count3;
            int ans = max(count1, count2);

            //check if there exits other number between the given range

            int k1 = Start[arr[x]] + counter[arr[x]];
            int k2 = Start[arr[y]] - 1;

            if(k1 <= k2){
                count3 = query(1, 1, n, k1, k2);
                ans = max(ans, count3);
                printf("%d\n", ans);
            }
            else
                printf("%d\n", ans);
        }
    }

    return 0;
}
