#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define MAX 2005
using namespace std;

typedef long long ll;

ll tree[MAX][MAX], max_x, max_y;

void update(int x, int y, int value)
{
    int y1;
    while(x <= max_x){
        y1 = y;
        while(y1 <= max_y){
            tree[x][y1] += (ll) value;
            y1 += (y1 & -y1);
        }
        x += (x & -x);
    }
}

ll query(int x, int y)
{
    int y1;
    ll sum = 0;
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
    int n, m, q, x1, y1, x2, y2, value, cmd;

    scanf("%d %d %d", &n, &m, &q);
    max_x = n, max_y = m;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            scanf("%d", &value);
            update(i, j, value);
        }
    }

    ll r1, r2, r3, r4;

    while(q--){
        scanf("%d", &cmd);
        if(cmd == 1){
            scanf("%d %d %d", &x1, &y1, &value);
            update(x1, y1, value);
        }
        else{
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            x1--, y1--, x2--, y2--;
            r1 = query(x2+1, y2+1);
            r2 = query(x1, y1);
            r3 = query(x2+1, y1);
            r4 = query(x1, y2+1);
            printf("%lld\n", r1 - r3 - r4 + r2);
        }
    }

    return 0;
}
