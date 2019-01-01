#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#define MAX 100005
using namespace std;

typedef long long lint;

int Z, I, M;

int f(int x)
{
    return (Z * x + I) % M;         //random number generation
}

int main()
{
    int L, cases = 1;
    int hare, tortoise, lambda, meu;

    while(scanf("%d %d %d %d", &Z, &I, &M, &L) == 4){
        if(!Z && !I && !M && !L)
            break;
        bool cycle_found = false;

        hare = L, tortoise = L;     //initial value for hare and tortoise

        while(!cycle_found){
            tortoise = f(tortoise);
            hare = f(f(hare));          //need two move
            if(hare == tortoise)
                cycle_found = true;
        }

        hare = L;   meu = 0;

        //move hare in starting position and begin moving 1 step both hare and tortoise
        while(hare != tortoise){
            meu++;
            hare = f(hare);
            tortoise = f(tortoise);
        }

        int i = 0;
        hare = L;

        while(i <= meu){
            i++;
            hare = f(hare);
        }

        tortoise = f(hare);
        lambda = 1;     //initial length of cycle

        while(hare != tortoise){
            tortoise = f(tortoise);
            lambda++;
        }

        printf("Case %d: %d\n", cases++, lambda);
    }

    return 0;
}
