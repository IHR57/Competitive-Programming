#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#define MAX 2005
#define debug (printf("PINK FLOYD:)\n"))
using namespace std;

vector<int> prefix_function(char str[])
{
    int len = strlen(str);
    vector<int> pi(MAX);

    for(int i = 1; i < len; i++){
        int j = pi[i - 1];
        while(j > 0 && str[i] != str[j]){
            j = pi[j-1];
        }
        if(str[i] == str[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

int main()
{
    int test;
    char str[MAX];

    scanf("%d", &test);

    while(test--){
        scanf("%s", str);
        vector<int> pi = prefix_function(str);
        int len = strlen(str);
        int k = pi[len - 1];
        for(int j = 0; j < 8; j++){
            if(k == len){
                k = pi[len-1];
            }
            printf("%c", str[k]);
            k++;
        }

        printf("...\n");
    }

    return 0;
}
