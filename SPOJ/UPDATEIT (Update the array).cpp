#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAX 10005
using namespace std;

int tree[MAX], n;

void update(int x, int value)
{
    while(x <= n){
        tree[x] += value;
        x += (x & -x);
    }
}

int query(int x)
{
    int sum = 0;

    while(x > 0){
        sum += tree[x];
        x -= (x & -x);
    }

    return sum;
}

int main()
{
    int test, u, q, x, y, value;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &n, &u);     //number of element in array and number of update operation
        memset(tree, 0, sizeof(tree));

        for(int i = 0; i < u; i++){
            scanf("%d %d %d", &x, &y, &value);
            x++, y++;           //1 based
            update(x, value);           //range update
            update(y+1, -value);
        }

        scanf("%d", &q);        //number of query

        for(int i = 0; i < q; i++){
            scanf("%d", &x);
            x++;
            printf("%d\n", query(x));
        }
    }

    return 0;
}
