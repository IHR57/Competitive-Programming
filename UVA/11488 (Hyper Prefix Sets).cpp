#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
#define MAX 400005
using namespace std;

int node[MAX][3], nodeNo, root;
int Max, nodeCount[MAX];

void init()
{
    nodeNo = 0, root= 0; Max = 0;

    for(int i = 0; i < 2; i++){     //initialize root node
        node[root][i] = -1;
    }

    for(int i = 0; i < MAX; i++){
        nodeCount[i] = 0;
    }
}

void insertWord(char* str)
{
    int len = strlen(str);
    int current = root;

    if(len > Max)
        Max = len;      //special case

    for(int i = 0; i < len; i++){
        int id = str[i] - 48;       //converting into integer
        if(node[current][id] == -1){
            node[current][id] = ++nodeNo;
            nodeCount[nodeNo] += 1;
            for(int j = 0; j < 2; j++){
                node[nodeNo][j] = -1;
            }
        }
        else{
            nodeCount[node[current][id]] += 1;
            if(nodeCount[node[current][id]] * (i+1) > Max)
            {
                Max = nodeCount[node[current][id]] * (i+1);     //update Max;
            }
        }
        current = node[current][id];
    }
}

int main()
{
    int test, totalWord;

    scanf("%d", &test);

    while(test--){
        init();
        scanf("%d", &totalWord);
        while(totalWord--){
            char str[220];
            scanf("%s", str);
            insertWord(str);
        }

        printf("%d\n", Max);
    }

    return 0;
}
