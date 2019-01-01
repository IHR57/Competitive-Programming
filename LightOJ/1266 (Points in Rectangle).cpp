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
#define MAX 1005
#define pb push_back
#define all(c) (c.begin(), c.end())
#define mem(a, b) memset(a, b, sizeof(a))
#define EPS 1e-10
#define PI 3.14159265358979323846
#define mp make_pair
#define read freopen("input.txt", "r", stdin);
#define write freopen("output.txt", "w", stdout);
using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<char> vc;
typedef long long ll;
typedef unsigned long long ull;

int tree[MAX][MAX];

void update(int x, int y, int value)
{
    int y1;
    while(x <= MAX){
        y1 = y;
        while(y1 <= MAX){
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
    //read; write;

    int test, caseNo = 1, q, x1, y1, x2, y2, cmd;

    scanf("%d", &test);

    while(test--){
        scanf("%d", &q);

        mem(tree, 0);

        printf("Case %d:\n", caseNo++);

        for(int i = 0; i < q; i++){
            scanf("%d", &cmd);
            if(cmd == 0){
                scanf("%d %d", &x1, &y1);
                int r1 = query(x1+1, y1+1);
                int r2 = query(x1, y1);
                int r3 = query(x1, y1+1);
                int r4 = query(x1+1, y1);

                int value = (r1 - r3 - r4 + r2) - 1;
                //cout<<value<<endl;
                if(value < 0){
                    update(x1+1, y1+1, 1);
                }
            }
            else{
                scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
                int r1 = query(x2+1, y2+1);
                int r2 = query(x1, y1);
                int r3 = query(x2+1, y1);
                int r4 = query(x1, y2+1);

                printf("%d\n", r1 - r3 - r4 + r2);
            }
        }
    }

    return 0;
}
