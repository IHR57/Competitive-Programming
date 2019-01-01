#include <bits/stdc++.h>
#define MAX 1000005
using namespace std;

char str[MAX], patt[MAX];
int pi[MAX];

void prefixFunction(char str[])
{
    memset(pi, 0, sizeof(pi));
    int len = strlen(str);

    for(int i = 1; i < len; i++){
        int j = pi[i-1];
        while(j > 0 && str[i] != str[j])
            j = pi[j-1];
        if(str[i] == str[j])
            j++;
        pi[i] = j;
    }
}

vector<int> matching(char str[], char patt[])
{
    vector<int> v;
    prefixFunction(str);
    int j = 0, len = strlen(str), n = strlen(patt);

    for(int i = 0; i < len; i++){
        while(j > 0 && str[i] != patt[j]){
            j = pi[j-1];
        }
        if(str[i] == patt[j])
            j++;
        if(j == n){
            v.push_back(i - n + 2);
        }
    }

    return v;
}

int main()
{
    int test, line = 0;
    scanf("%d", &test);

    while(test--){
        scanf("%s %s", str, patt);
        vector<int> v = matching(str, patt);
        if(line)
            printf("\n");
        line = 1;
        if(!v.empty()){
            printf("%d\n", v.size());
            for(int i = 0; i < v.size(); i++){
                printf("%d ", v[i]);
            }
            printf("\n");
        }
        else{
            printf("Not Found\n");
        }
    }

    return 0;
}
