/*
    Sparse Table can be applied if and only if
        1) Array is immutable
        2) Function F is associative: F(a, b, c) = F(F(a, b), c) = F(a, F(b, c))

    Build Time: O(nlog(n))
    Query Time: O(1)
*/
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int arr[MAX], n;
int ST[20][MAX];

void buildST()          //Sparse Table for RMQ
{
    for(int i = 0; i < n; i++)
        ST[0][i] = i;

    for(int k = 1; (1 << k) <= n; k++){
        for(int i = 0; i + (1 << k) <= n; i++){
            int x = ST[k-1][i];
            int y = ST[k-1][i+(1<<(k-1))];
            ST[k][i] = (arr[x] <= arr[y]) ? x : y;
        }
    }
}

int RMQ(int i, int j)
{
    int k = log2(j - i + 1);
    int x = ST[k][i];
    int y = ST[k][j-(1<<k) + 1];

    return (arr[x] <= arr[y]) ? x : y;
}

int main()
{
    int u, v;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    buildST();
    int q;
    scanf("%d", &q);
    for(int i = 0; i < q; i++){
        scanf("%d %d", &u, &v);
        printf("%d\n", arr[RMQ(u, v)]);
    }

    return 0;
}
