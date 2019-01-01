#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    char str[50];
    int index[100] = {0};

    cin>>str;

    int len = strlen(str);

    bool flag = true;

    for(int i = 0; i < len; i++){
        if(str[i] == '1')
            index[i] = 1;
        else if(str[i] == '4'){
            if(i - 2 >= 0 && str[i-1] == '4' && str[i-2] == '1')
                index[i] = 1;
            else if(i - 1 >= 0 && str[i-1] == '1')
                index[i] = 1;
        }
    }

    int count = 0;
    for(int i = 0; i < len; i++){
        if(index[i] == 1)
            count++;
    }

    if(count == len)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
