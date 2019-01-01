#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int flag;

struct node
{
    bool endmark;
    node* next[11];

    node()              //initialize when new node created
    {
        endmark = false;
        for(int i = 0; i < 10; i++){
            next[i] = NULL;
        }
    }
}*root;

void insertNumber(char* str, int len)
{
    node* current = root;

    for(int i = 0; i < len; i++){
        int id = str[i] - 48;
        if(current->next[id] == NULL){
            if(current->endmark == true)        //if we find a prefix
                flag = 1;
            current->next[id] = new node();
        }
        current = current->next[id];
    }
    current->endmark = true;

    int i = str[len-1] - 48;
    if(current->next[i] != NULL)        //condition for checking prefix
        flag = 1;
}

void del(node* current)
{
    for(int i = 0; i < 10; i++){
        if(current->next[i])
            del(current->next[i]);
    }

    delete current;
}

int main()
{
    int test, cases = 1, totalNumber;

    scanf("%d", &test);

    while(test--){
        scanf("%d", &totalNumber);
        flag = 0;
        root = new node();
        while(totalNumber--){
            char str[15];
            scanf("%s", str);
            int len = strlen(str);
            insertNumber(str, len);
        }

        //printf("Case %d: ", cases++);
        (flag) ? printf("NO\n") : printf("YES\n");
        del(root);
    }

    return 0;
}
