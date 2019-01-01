#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#define MAX 100005
#define pb push_back
#define all(c) (c.begin(), c.end())
#define memo(a, b) memset(a, b, sizeof(a))
#define EPS 1e-8
#define PI 3.14159265358979323846
#define mp make_pair
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> ppi;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;

int tree[4*MAX], lazy[4*MAX];

int gcd(int a, int b)
{
    if(a % b == 0)
        return b;
    return gcd(b, a % b);
}

void shift(int id, int low, int high, int x)
{
    tree[id] = (high - low + 1) * x;
    if(low !=  high){
        lazy[2*id] = x;
        lazy[2*id+1] = x;
    }

    lazy[id] = -1;
}

void update(int id, int low, int high, int i, int j, int value)
{
    if(lazy[id] != -1){
        shift(id, low, high, lazy[id]);
    }
    if(low > high || i > high || j < low)
        return;
    if(low >= i && high <= j){
        shift(id, low, high, value);
        return;
    }

    int mid = (low + high) >> 1;
    update(id*2, low, mid, i, j, value);
    update(id*2+1, mid + 1, high, i, j, value);

    tree[id] = tree[2*id] + tree[2*id+1];
}

int query(int id, int low, int high, int i, int j)
{
    if(lazy[id] != -1){
        shift(id, low, high, lazy[id]);
    }
    if(low > high || i >  high || j < low)
        return 0;
    if(low >= i &&  high <= j){
        return tree[id];
    }

    int mid = (low + high) >> 1;

    return query(2*id, low, mid, i, j) + query(2*id+1, mid + 1, high, i, j);
}

int main()
{
    // freopen("input.txt",  "r", stdin);
    // freopen("output.txt", "w", stdout);

    int test, n, q, x, y, cmd, value, caseNo = 1;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &n, &q);
        memo(tree, 0);
        memo(lazy, -1);

        printf("Case %d:\n", caseNo++);
        while(q--){
            scanf("%d", &cmd);
            if(cmd == 1){
                scanf("%d %d %d", &x, &y, &value);
                update(1, 0, n - 1, x, y, value);
            }
            else{
                scanf("%d %d", &x, &y);
                int ans = query(1, 0, n - 1, x, y);
                //printf("%d\n", ans);
                int tmp = (y - x + 1);
                int g = gcd(ans, tmp);
                if(ans % tmp != 0){
                    printf("%d/%d\n", ans/g, tmp/g);
                }
                else
                    printf("%d\n", ans/tmp);
            }
        }
    }

    return 0;
}
