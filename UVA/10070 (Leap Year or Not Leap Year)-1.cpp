#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#define MAX 100005
using namespace std;

int check(string str, int n)
{
    int length  = str.size();
    int rem = 0;

    for(int i = 0; i < length; i++){
        rem = (((rem * 10) + (str[i] - 48)) % n);
    }

    return rem;
}

int main()
{
    string str;
    int flag, blank = 0;

    while(cin>>str){
        flag = 0;
        if(blank)
            printf("\n");
        blank = 1;

        if(!check(str, 15)){
            if(!check(str, 4) || !check(str, 400)){
                printf("This is leap year.\n");
                printf("This is huluculu festival year.\n");
            }
            else
                printf("This is huluculu festival year.\n");
        }
        else if(!check(str, 4) || !check(str, 400)){
            if(!check(str, 55)){
                printf("This is leap year.\n");
                printf("This is bulukulu festival year.\n");
            }
            else
                printf("This is leap year.\n");
        }
        else if((!check(str, 4) || !check(str, 400)) && !check(str, 55) && !check(str, 15)){
            printf("This is leap year.\n");
            printf("This is huluculu festival year.\n");
            printf("This is bulukulu festival year.\n");
        }

        else
            printf("This is an ordinary year.\n");
    }

    return 0;
}
