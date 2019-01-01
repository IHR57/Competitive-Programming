#include <iostream>
#include <cstdio>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
#define pb push_back
#define MAX 2010
using namespace std;

typedef long long lint;
int visited[MAX][MAX];

int breadthFirst(char* str, int tx, int ty)
{
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++)
            visited[i][j] = 0;
    }

    visited[tx][ty] = 1;
    int count = 0;

    int len = strlen(str);

    for(int i = 0; i < len; i++){
        if(str[i] == 'Q')
            break;
        if(str[i] == 'U'){
            tx += 1;
        }
        else if(str[i] == 'R'){
            ty += 1;
        }
        else if(str[i] == 'L'){
            ty -= 1;
        }
        else if(str[i] == 'D'){
            tx -= 1;
        }

        if(visited[tx][ty] == 1){
            count++;
        }
        else{
            visited[tx][ty] = 1;
        }
    }

    return count;
}

int main()
{
    char str[MAX];

    while(scanf("%s", str) == 1){
        if(str[0] == 'Q')   break;
        int result = breadthFirst(str, 1000, 1000);
        printf("%d\n", result);
    }

    return 0;
}
