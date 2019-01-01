#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;

int main()
{
    char first[110], second[110], temp[110];

    cin>>first;
    cin>>second;

    int len = strlen(first);

    int i, j;

    for(i = 0, j = len - 1; i < len; i++, j--){
        temp[j] = first[i];
    }
    temp[len] = '\0';
    //cout<<temp<<endl;

    if(strcmp(temp, second) == 0)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
