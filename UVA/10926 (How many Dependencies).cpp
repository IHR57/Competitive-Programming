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

#define MAX 105
#define pb push_back
#define eps 1e-11

typedef long long lint;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int  inf = 1<<28;
int n, dist[MAX][MAX];

void init()
{
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            if(i == j)  dist[i][j] = 0;
            else    dist[i][j] = 0;
        }
    }
}

void transitiveClosure()
{
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                dist[i][j] |= (dist[i][k] & dist[k][j]);
            }
        }
    }
}

int main()
{
    int connected, node;

    while(scanf("%d", &n) == 1){
        if(!n)  break;
        init();
        for(int i = 0; i < n; i++){
            scanf("%d", &connected);
            for(int j = 0; j < connected; j++){
                scanf("%d", &node);
                node--;
                dist[i][node] = 1;      //directed
            }
        }

        transitiveClosure();
        int count, idx, Max = -1;

        for(int i = 0; i < n; i++){
            count = 0;
            for(int j = 0; j < n; j++){
                if(i != j){
                    if(dist[i][j] > 0)  count++;
                }
            }
            if(count > Max){
                Max = count;
                idx = i;
            }
        }

        printf("%d\n", idx + 1);
    }

    return 0;
}


