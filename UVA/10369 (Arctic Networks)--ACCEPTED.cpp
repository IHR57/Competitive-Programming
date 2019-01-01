//Problem ID: UVA 10369 (Arctic Network)
//Programmer: IQBAL HOSSAIN     Description: MST (Minimum Spanning Forest)
//Date: 28-09-17
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <sstream>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

#define MAX 505
#define pb push_back
#define eps 1e-11

typedef long long lint;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int  inf = 1<<28;
int satellite, posts;
int parent[MAX];

struct node
{
    int u, v;
    double w;
};

bool operator<(node A, node B)
{
    return A.w < B.w;
}

vector<node> V;

double calDistance(int x1, int y1, int x2, int y2)
{
    return (double) sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int findSet(int x)
{
    if(parent[x] == x)
        return x;
    return parent[x] = findSet(parent[x]);
}

double kruskal()
{
    double ans;
    int count = 0;

    for(int i = 0; i <= posts; i++)
        parent[i] = i;

    int sz = V.size();
    sort(V.begin(), V.end());

    for(int i = 0; i < sz; i++){
        int x = findSet(V[i].u);
        int y = findSet(V[i].v);
        if(x != y){
            count++;
            parent[x] = y;
            ans = V[i].w;
            if(count == posts - satellite)
                break;
        }
    }

    return ans;
}

int main()
{
    int test, x, y;

    scanf("%d", &test);

    while(test--){
        pii coord[MAX];

        scanf("%d %d", &satellite, &posts);
        for(int i = 0; i < posts; i++){
            scanf("%d %d", &x, &y);
            coord[i] = make_pair(x, y);
        }

        for(int i = 0; i < posts; i++){
            for(int j = i + 1; j < posts; j++){
                double dist = calDistance(coord[i].first, coord[i].second, coord[j].first, coord[j].second);
                //cout<<i<<" "<<j<<": "<<dist<<endl;
                node temp;
                temp.u = i, temp.v = j, temp.w = dist;
                V.pb(temp);
            }
        }

        double result = kruskal();

        printf("%0.2lf\n", result);

        V.clear();
    }

    return 0;
}
