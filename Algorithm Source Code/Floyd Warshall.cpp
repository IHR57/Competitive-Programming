#include <iostream>
#include <algorithm>
#include <cstdio>
#define MAX 50
using namespace std;

const int INF = 999;
int dist[MAX][MAX], graph[MAX][MAX], p[MAX][MAX], N;

void init()
{
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            dist[i][j] = graph[i][j];
        }
    }

    for(int i = 0; i < N; i++){
        dist[i][i] = 0;
    }
}

void printSolution()
{
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(dist[i][j] == INF){
                printf("%7s", "INF");
            }
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

void floydWarshall()
{
    for(int k = 0; k < N; k++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    printSolution();
}

int main()
{
    printf("Enter number of vertex: ");
    scanf("%d", &N);

    printf("Input Adjacency Matrix: ");

    init();
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%d", &graph[i][j]);
        }
    }

    floydWarshall();

    return 0;
}
