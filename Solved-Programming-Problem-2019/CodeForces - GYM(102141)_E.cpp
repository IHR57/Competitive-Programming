//Problem ID: CodeForces - GYM 102141 (Consecutive Letters) - (MIST IUPC 2019)
//Programmer: IQBAL HOSSAIN     Description: Segment Tree
//Date: 17/03/19
//Problem Link: https://codeforces.com/gym/102141
#include <bits/stdc++.h>
#define MAX 200050
using namespace std;

int Start[MAX], End[MAX];
multiset<int> s[30];

struct info{
    int lidx, ridx;
}tree[4*MAX], lazy[4*MAX];

char str[MAX];

void init()
{
    for(int i = 0; i < 4 * MAX; i++){
        tree[i].lidx = 0, tree[i].ridx = 0;
        lazy[i].lidx = -1, lazy[i].ridx = -1;
    }
}
void build(int nodeNo, int low, int high)
{
    if(low == high){
        tree[nodeNo].lidx = Start[low];
        tree[nodeNo].ridx = End[low];
    }
    else{
        int mid = (low + high) >> 1;
        build(nodeNo * 2, low, mid);
        build(nodeNo * 2 + 1, mid + 1, high);
    }
}

void update(int nodeNo, int low, int high, int i, int j, info temp)
{
    if(lazy[nodeNo].lidx != -1){
        tree[nodeNo] = temp;
        if(low != high){
            lazy[nodeNo * 2] = temp;
            lazy[nodeNo * 2 + 1] = temp;
        }
        lazy[nodeNo].lidx = -1;
        lazy[nodeNo].ridx = -1;
    }
    if(low > high || low > j || high < i)
        return;
    if(low >= i && high <= j){
        tree[nodeNo] = temp;
        if(low != high){
            lazy[nodeNo * 2] = temp;
            lazy[nodeNo * 2 + 1] = temp;
        }
        return;
    }
    int mid = (low + high) >> 1;
    update(nodeNo * 2, low, mid, i, j, temp);
    update(nodeNo * 2 + 1, mid + 1, high, i, j, temp);
}

info get(int nodeNo, int low, int high, int pos)
{
    if(lazy[nodeNo].lidx != -1){
        tree[nodeNo] = lazy[nodeNo];
        if(low != high){
            lazy[nodeNo * 2] = lazy[nodeNo];
            lazy[nodeNo * 2 + 1] = lazy[nodeNo];
        }
        lazy[nodeNo].lidx = -1;
        lazy[nodeNo].ridx = -1;
    }
    if(low > high){
        return {0, 0};
    }
    if(low == high)
        return tree[nodeNo];
    int mid = (low + high) >> 1;
    if(pos <= mid)
        return get(nodeNo * 2, low, mid, pos);
    else
        return get(nodeNo * 2 + 1, mid + 1, high, pos);
}

int main()
{
    int test, caseno = 1, query;

    scanf("%d", &test);

    while(test--){
        scanf("%s", str);
        scanf("%d", &query);

        int len = strlen(str);

        Start[0] = 0;
        for(int i = 1; i < len; i++){
            if(str[i] != str[i-1])
                Start[i] = i;
            else
                Start[i] = Start[i-1];
        }
        End[len-1] = len-1;
        for(int i = len - 2; i >= 0; i--){
            if(str[i] != str[i+1])
                End[i] = i;
            else
                End[i] = End[i+1];
        }

        init();
        build(1, 0, len - 1);

        int cmd, pos;

        printf("Case %d:\n", caseno++);
        for(int i = 0; i < query; i++){
            scanf("%d %d", &cmd, &pos);
            info temp = get(1, 0, len - 1, pos);
            if(cmd == 1){
                printf("%d\n", temp.ridx - temp.lidx + 1);
            }
            else{
                if(pos - 1 >= 0 && str[pos-1] == str[pos]){
                    info t;
                    t.lidx = temp.lidx, t.ridx = pos - 1;
                    update(1, 0, len - 1, temp.lidx, pos - 1, t);
                }
                if(pos + 1 < len && str[pos+1] == str[pos]){
                    info t;
                    t.lidx = pos + 1, t.ridx = temp.ridx;
                    update(1, 0, len - 1, pos + 1, temp.ridx, t);
                }
                str[pos] = '@';
            }
        }
    }

    return 0;
}
