#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int test, hour, minute;

    scanf("%d", &test);

    while(test--){
        scanf("%2d:%2d", &hour, &minute);

        if(hour == 12 && minute!=0){
            hour = 11;
            minute = 60 - minute;

            if(minute>=10)
                printf("%d:%d\n", hour, minute);
            else if(minute<10)
                printf("%d:0%d\n", hour, minute);
        }
        else if(hour!=0 && minute!=0){
            minute = 60 - minute;
            hour = 11 - hour;
            if(hour == 0)
                hour = 12;
            if(hour>=10 && minute>=10)
                printf("%d:%d\n", hour, minute);
            else if(hour>=10 && minute<10)
                printf("%d:0%d\n", hour, minute);
            else if(hour<10 && minute>=10)
                printf("0%d:%d\n", hour, minute);
            else if(hour<10 && minute<10)
                printf("0%d:0%d\n", hour, minute);
        }
        else if(minute == 0){
            hour = 12 - hour;
            if(hour == 0)
                hour = 12;
            if(hour>=10)
                printf("%d:00\n", hour);
            else
                printf("0%d:00\n", hour);
        }
    }

    return 0;
}
