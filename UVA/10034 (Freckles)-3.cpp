#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <queue>
#define MAX 5000
using namespace std;

int parent[MAX];

void init()
{
    for(int i = 0; i < MAX; i++){
        parent[i] = i;
    }
}
struct node
{
    int n1;
    int n2;
    double cost;
};

bool compare(node A, node B)
{
    return A.cost < B.cost;
}

node edge[MAX];

struct coordinate       //for storing x and y
{
    double x;
    double y;
};

int findSet(int x)
{
    if(parent[x] == x)
        return x;
    return parent[x] = findSet(parent[x]);
}

coordinate cord[MAX];

int main()
{
    int n, test, Case = 0;
    double a, b, sum;

    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);

        for(int i = 0; i < n; i++){
            scanf("%lf %lf", &cord[i].x, &cord[i].y);
        }

        init();

        int c = 0;

        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                a = pow((cord[i].x - cord[j].x), 2);
                b = pow((cord[i].y - cord[j].y), 2);
                edge[c].n1 = i;
                edge[c].n2 = j;
                edge[c].cost = sqrt(a + b);
                c++;
            }
        }

        sort(edge, edge+c, compare);

        int count = 0;
        sum = 0;

        for(int i = 0; i < c; i++){
            int x = findSet(edge[i].n1);
            int y = findSet(edge[i].n2);

            if(x != y){
                parent[x] =y;
                sum += edge[i].cost;
                count++;
                if(count == n)
                    break;
            }
        }
        if(Case != 0)
            printf("\n");
        printf("%0.2lf\n", sum);
        Case++;
    }

    return 0;
}
