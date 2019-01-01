#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int INF = 1<<28;

void findPath(int next[][20], int i, int j)
{
    printf("Path = %d", i);

    while(i != j){
        i = next[i][j];
        printf(" %d", i);
    }

    printf(";");
}

int main()
{
    int matrix[20][20], next[20][20], n, cost, a;
    int source, destination, number, cases = 1;

    while(scanf("%d", &n) == 1){
        if(n == 0)
            break;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(i == j)
                    matrix[i][j] = 0;
                else
                    matrix[i][j] = INF;
                next[i][j] = j;
            }
        }

        for(int i = 1; i <= n; i++){
            scanf("%d", &number);
            for(int j = 0; j < number; j++){
                scanf("%d %d", &a, &cost);
                matrix[i][a] = cost;
            }
        }

        scanf("%d %d", &source, &destination);
        //apply Floyd Warshall algorithm

        for(int k = 1; k <= n; k++){
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                    if(matrix[i][k] + matrix[k][j] < matrix[i][j]){
                        matrix[i][j] = matrix[i][k] + matrix[k][j];
                        next[i][j] = next[i][k];
                    }
                }
            }
        }
        printf("Case %d: ", cases++);
        findPath(next, source, destination);      //print the path from source to destination
        printf(" %d second delay\n", matrix[source][destination]);      //shortest path
    }

    return 0;
}
