#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1<<28;

int main()
{
    int matrix[105][105], u, v, test, cases = 1, node, edge;
    int source, destination;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d", &node, &edge);

        for(int i = 0; i < node; i++){
            for(int j = 0; j < node; j++){
                (i == j) ? matrix[i][j] = 0 : matrix[i][j] = INF;
            }
        }
        for(int i = 0; i < edge; i++){
            scanf("%d %d", &u,  &v);
            matrix[u][v] = 1;
            matrix[v][u] = 1;       //directed graph
        }
        scanf("%d %d", &source, &destination);

        //apply all pair shortest path

        for(int k = 0 ; k < node; k++){
            for(int i = 0; i < node; i++){
                for(int j = 0; j < node; j++){
                    matrix[i][j] = min(matrix[i][k] + matrix[k][j] , matrix[i][j]);
                }
            }
        }

        int result = 0;
        for(int i = 0; i < node; i++){
            if(matrix[source][i] != INF && matrix[i][destination] != INF){
                result = max(result, matrix[source][i] + matrix[i][destination]);
            }
        }

        printf("Case %d: %d\n", cases++, result);
    }

    return 0;
}
