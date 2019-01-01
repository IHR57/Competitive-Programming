#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX 100005
using namespace std;

int n, ans, bit[2][MAX];

void update(int id, int idx, int value)
{
    while(idx < MAX){
        bit[id][idx] = max(bit[id][idx], value);
        idx += (idx & -idx);
    }
}

int query(int id, int idx)
{
    int res = 0;
    while(idx > 0){
        res = max(bit[id][idx], res);
        idx -= (idx & -idx);
    }

    return res;
}

int main()
{
    int totalCoin, totalDiamond;
    int beauty, cost;
    char id;

    scanf("%d %d %d", &n, &totalCoin, &totalDiamond);

    int j = 0;
    for(int i = 0; i < n; i++){
        scanf("%d %d %c", &beauty, &cost, &id);
        if(id == 'C'){
            if(cost <= totalCoin){
                int t1 = query(0, totalDiamond);
                int t2 = query(1, totalCoin - cost);
                int t3 = max(t1, t2);
                if(t3){
                    ans = max(ans, t3+beauty);
                }
            }
            update(1, cost, beauty);
        }
        else if(id == 'D'){
            if(cost <= totalDiamond){
                int t1 = query(1, totalCoin);
                int t2 = query(0, totalDiamond - cost);
                int t3 = max(t1, t2);
                if(t3)
                    ans = max(ans, t3+beauty);
            }
            update(0, cost, beauty);
        }
    }

    printf("%d\n", ans);

    return 0;
}
