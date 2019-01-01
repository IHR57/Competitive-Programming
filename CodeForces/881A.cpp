//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main()
{
    char str[200];

    cin>>str;

    int len = strlen(str);
    int idx = -1, count = 0;

    for(int i = 0; i < len; i++){
        if(str[i] == '1'){
            idx = i;
            break;
        }
    }

    for(int i = idx + 1; i < len; i++){
        if(str[i] == '0')
            count++;
    }

    if(idx != -1 && count >= 6){
        printf("yes\n");
    }
    else
        printf("no\n");

    return 0;
}
