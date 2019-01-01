#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;

int main()
{
    char str[30];
    int len, k;

    cin>>str>>k;

    len = strlen(str);

    int count = 0, non_zero = 0;

    int j = 0;
    for(int i = len-1; i >= 0; i--){
        if(str[i] == '0')
            count++;            //number of digit including zero
        j++;
        if(count == k)
            break;
    }

    if(count < k){
        non_zero = len - 1;     //if number of zero less than required zero
    }

    else{
        for(int i = len-1; i >= len - j; i--){
            if(str[i] != '0')
                non_zero++;     //number of non-zero digit between required zero
        }
    }

    cout<<non_zero<<endl;

    return 0;
}
