#include <bits/stdc++.h>
#define MAX 2030
using namespace std;

int tree[MAX][MAX], max_x, max_y;

void update(int x, int y, int value)
{
    int y1;
    while(x <= max_x){
        y1 = y;
        while(y1 <= max_y){
            tree[x][y1] += value;
            y1 += (y1 & -y1);
        }
        x += (x & -x);
    }
}

int query(int x, int y)
{
    int sum = 0, y1;
    while(x > 0){
        y1 = y;
        while(y1 > 0){
            sum += tree[x][y1];
            y1 -= (y1 & -y1);
        }
        x -= (x & -x);
    }

    return sum;
}

int main()
{
    int test, n, x1, y1, x2, y2, value;

    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);
        max_x = max_y = n;
        char str[20];

        memset(tree, 0, sizeof(tree));

        while(scanf("%s", str) == 1){
            if(!strcmp(str, "END")){
                break;
            }
            if(!strcmp(str, "SUM")){
                scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
                int r1 = query(x1, y1);
                int r2 = query(x2+1, y2+1);
                int r3 = query(x2+1, y1);
                int r4 = query(x1, y2+1);

                printf("%d\n", r1-r3-r4+r2);
            }
            else{
                scanf("%d %d %d", &x1, &y1, &value);
                int r1 = query(x1+1, y1+1);
                int r2 = query(x1, y1);
                int r3 = query(x1, y1+1);
                int r4 = query(x1+1, y1);
                update(x1+1, y1+1, value - (r1-r3-r4+r2));
            }
        }
        printf("\n");
    }

    return 0;
}
