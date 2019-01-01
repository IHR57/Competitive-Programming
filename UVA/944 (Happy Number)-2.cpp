#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#define MAX 100005
using namespace std;

typedef long long lint;

int isHappy[MAX], cycleLength[MAX];

int f(int x)        //this function will return the summation of every digit after squaring each digit
{
    int ans = 0;

    while(x != 0){
        int temp = x % 10;
        x = x / 10;
        ans += (temp * temp);
    }

    return ans;
}

int main()
{
    int hare, tortoise;

    memset(isHappy, 0, sizeof(isHappy));            //initialize all number are unhappy

    isHappy[1] = 1, cycleLength[1] = 0;     //special case;

    for(int i = 2; i < MAX; i++){           //generate all happy number with cycle length;
        bool cycleFound = false;
        hare = i, tortoise = i;

        int count = 0;

        while(!cycleFound){
            tortoise = f(tortoise);
            hare = f(f(hare));
            count++;
            /*if(tortoise == 1){
                isHappy[i] = 1;         //this is a happy number
                cycleLength[i] = count;
                break;
            }*/
            if(hare == tortoise){
                if(hare == 1){
                    isHappy[i] = 1;
                    cycleLength[i] = count;
                }
                cycleFound = true;
            }
        }
    }

    int low, high, newLine = 0;

    while(scanf("%d %d", &low, &high) == 2){
        if(newLine){
            printf("\n");
        }
        newLine = 1;
        for(int i = low; i <= high; i++){
            if(isHappy[i]){
                printf("%d %d\n", i, cycleLength[i] + 1);
            }
        }
    }

    return 0;
}

