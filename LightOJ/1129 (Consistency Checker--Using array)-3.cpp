#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAX_NODE 100005
#define MAX_LEN 15
using namespace std;

//char str[MAX_LEN];
int node[MAX_NODE][MAX_LEN];
int root, nodeNo, isWord[MAX_NODE], flag;

void init()
{
    root = 0;
    nodeNo = 0;

    for(int i = 0; i < 10; i++){
        node[root][i] = -1;
    }
}

void insertWord(char* str)
{
    int count =  0;
    int len = strlen(str);
    int current = root;

    for(int i = 0; i < len; i++){
        int id = str[i] - 48;
        if(node[current][id] == -1){
            node[current][id] = ++nodeNo;
            for(int j = 0; j < 10; j++){
                node[nodeNo][j] = -1;
            }
        }
        else            //if there exits prefix
            count++;
        current = node[current][id];
        if(isWord[current])
            flag = 1;
    }

    if(count == len)        //if find prefix
        flag = 1;
    isWord[current] = 1;        //end mark
}

int main()
{
    int test, cases = 1;
    int totalWord;

    scanf("%d", &test);

    while(test--){
        init();
        memset(isWord, 0, sizeof(isWord));
        scanf("%d", &totalWord);

        flag = 0;
        while(totalWord--){
            char str[15];
            scanf("%s", str);
            insertWord(str);
        }
        //printf("Case %d: ", cases++);
        (flag) ? printf("NO\n") : printf("YES\n");
    }

    return 0;
}

