#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
#define MAX 200005
using namespace std;

int node[MAX][6], countNode[MAX];
int nodeNo, root, Max;

void init()     //initialization
{
    root = 0;
    nodeNo = 0;
    Max = 0;

    for(int i = 0; i < 4; i++){
        node[root][i] = -1;
    }

    for(int i = 0; i < MAX; i++)        //making all node unvisited
        countNode[i] = 0;
}

void insertWord(char* str)
{
    int len = strlen(str);

    if(len > Max)       //this case will be true if there is no common prefix whose sum is greater
        Max = len;

    int current = root;         //we start from root node

    for(int i = 0; i < len; i++){
        int id = str[i] - 'A';      //getting integer id

        if(node[current][id] == -1){            //if not visited yet
            node[current][id] = ++nodeNo;
            countNode[nodeNo] += 1;             //make this node visited
            for(int j = 0; j < 4; j++){     //make all of his possible child node unvisited
                node[nodeNo][j] = -1;
            }
        }
        else{
            countNode[node[current][id]] += 1;      //if the node previously visited
            if((countNode[node[current][id]] * (i+1)) > Max)
                Max = countNode[node[current][id]] * (i+1);         //update Max if it is greater
        }

        current = node[current][id];        //move to the next node
    }

    //return Max;
}
int main()
{
    int test, cases = 1, totalWord;

    scanf("%d", &test);

    while(test--){
        init();
        scanf("%d", &totalWord);        //number of word have to be inserted

        //memset(countNode, 0, sizeof(countNode));        //makes all count node to zero

        while(totalWord--){
            char str[60];
            scanf("%s", str);

            int len = strlen(str);

            for(int i = 0; i < len; i++){           //mapping C G T with B C D for simplicity
                if(str[i] == 'C')   str[i] = 'B';
                else if(str[i] == 'G')     str[i] = 'C';
                else if(str[i] == 'T')     str[i] = 'D';
            }

            //int result = insertWord(str);
           insertWord(str);
        }

        printf("Case %d: %d\n", cases++, Max);
    }

    return 0;
}
