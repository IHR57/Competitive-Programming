//Problem ID: LightOJ - 1339 (Strongest Community)
//Programmer: IQBAL HOSSAIN     Description: Segment Tree
//Date: 01/05/19
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

vector<int> v[MAX];
int pos[MAX], arr[MAX], b[MAX];
int tree[4*MAX];

void build(int nodeNo, int low, int high)
{
    if(low == high){
        tree[nodeNo] = b[low];
        return;
    }
    int mid = (low + high) >> 1;
    build(nodeNo * 2, low, mid);
    build(nodeNo * 2 + 1, mid + 1, high);
    tree[nodeNo] = max(tree[nodeNo * 2], tree[nodeNo * 2 + 1]);
}

int query(int nodeNo, int tl, int tr, int l, int r)
{
    if(l > r)
        return 0;
    if(l == tl && r == tr)
        return tree[nodeNo];
    int tm = (tl + tr) >> 1;
    return max(query(nodeNo * 2, tl, tm, l, min(r, tm)), query(nodeNo * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

int main()
{
    int test, caseno = 1, n, c, q;

    scanf("%d",  &test);

    while(test--){
        scanf("%d %d %d", &n, &c, &q);
        int k = 1, prev = -1;
        for(int i = 1; i <= n; i++){
            scanf("%d", &arr[i]);
            if(arr[i] != prev){
                prev = arr[i];
                pos[arr[i]] = k;
                k++;
            }
            v[pos[arr[i]]].push_back(i);
        }
        for(int i = 1; i <= c; i++){
            b[i] = v[i].size();
        }

        printf("Case %d:\n", caseno++);

        build(1, 1, c);

        for(int i = 0; i < q; i++){
            int l, r;
            scanf("%d %d", &l, &r);
            int t1 = pos[arr[l]], t2 = pos[arr[r]];
            int ans;
            if(t1 == t2){
                ans = (r - l + 1);
            }
            else{
                if(t1 + 1 > t2 - 1){ //belong to adjacent group
                    int sz = v[t1].size();
                    ans = max(v[t1][sz - 1] - l + 1, r - v[t2][0] + 1);
                }
                else{
                    int sz = v[t1].size();
                    ans = max(v[t1][sz - 1] - l + 1, r - v[t2][0] + 1);
                    ans = max(ans, query(1, 1, c, t1 + 1, t2 - 1));
                }
            }
            printf("%d\n", ans);
        }
        for(int i = 0; i < MAX; i++)
            v[i].clear();
    }

    return 0;
}
