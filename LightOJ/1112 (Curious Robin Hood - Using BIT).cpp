#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
#define MAX 100005
using namespace std;

int f[MAX], tree[MAX];

void update(int idx, int n, int x)
{
    while(idx <= n){
        tree[idx] += x;
        idx += idx & (-idx);
    }
}

int query(int idx)
{
    int sum = 0;
    while(idx > 0){
        sum += tree[idx];
        idx -= idx & (-idx);
    }

    return sum;
}

int main()
{
    int test, cases = 1, n, command, r1, r2, q;

    scanf("%d", &test);

    while(test--){
        memset(tree, 0, sizeof(tree));

        scanf("%d %d", &n, &q);
        for(int i = 1; i <= n; i++){
            scanf("%d", &f[i]);
            update(i, n, f[i]);
        }

        printf("Case %d:\n", cases++);
        while(q--){
            scanf("%d", &command);
            if(command == 1){
                scanf("%d", &r1);
                r1++;
                update(r1, n, -f[r1]);
                printf("%d\n", f[r1]);
                f[r1] = 0;
            }
            else if(command == 2){
                scanf("%d %d", &r1, &r2);
                r1++;
                f[r1] += r2;
                update(r1, n, r2);
            }
            else if(command == 3){
                scanf("%d %d", &r1, &r2);
                r1++; r2++;
                int result1 = query(r2);
                int result2 = query(r1-1);

                printf("%d\n", result1 - result2);
            }
        }
    }

    return 0;
}
