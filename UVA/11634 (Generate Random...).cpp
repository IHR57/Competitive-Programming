#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#define MAX 100005
using namespace std;

typedef long long lint;

int f(int x)
{
    return ((x * x) / 100) % 10000;         //four digit in the middle
}

int main()
{
    int value;
    int hare, tortoise, lambda, meu;

    while(scanf("%d", &value) == 1){
        if(!value)  break;      //if value is zero

        bool cycleFound = false;        //this value will be true if there exits cycle

        hare = value , tortoise = value;

        while(!cycleFound){
            tortoise = f(tortoise);
            hare = f(f(hare));
            if(tortoise == hare)
                cycleFound = true;
        }

        hare = value;
        meu = 0;

        while(tortoise != hare){
            tortoise = f(tortoise);
            hare = f(hare);
            meu++;
        }

        hare = f(tortoise);
        lambda = 1;         //initial length

        while(tortoise != hare){        //find the cycle length
            hare = f(hare);
            lambda++;
        }

        printf("%d\n", lambda + meu);       //print number of different value in this sequence
    }

    return 0;
}
