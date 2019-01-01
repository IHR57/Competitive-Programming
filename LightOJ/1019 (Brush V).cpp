#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 105;

int matrix[MAX][MAX];
const int INF = 1<<28;

void FloydWarshall(int n)
{
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                matrix[i][j] = min(matrix[i][k] + matrix[k][j] , matrix[i][j]);
            }
        }
    }
}

int main()
{
    int test, node, edge, cases = 1;
    int u, v, w;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &node, &edge);

        for(int i = 1; i <= node; i++){
            for(int j = 1; j <= node; j++){
                (i == j) ? matrix[i][j] = 0 : matrix[i][j] = INF;
            }
        }

        for(int i = 0; i < edge; i++){
            scanf("%d %d %d", &u, &v, &w);
            if(w < matrix[u][v]){
                matrix[u][v] = w;
                matrix[v][u] = w;
            }
        }

        FloydWarshall(node);

        int dist = matrix[1][node];

        printf("Case %d: ", cases++);
        (dist == INF) ? printf("Impossible\n") : printf("%d\n", dist);
    }

    return 0;
}
